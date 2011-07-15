package org.concord.sensor.pasco;

import java.io.IOException;
import java.util.ArrayList;
import java.util.logging.Logger;

import org.concord.sensor.ExperimentConfig;
import org.concord.sensor.ExperimentRequest;
import org.concord.sensor.SensorConfig;
import org.concord.sensor.device.DeviceReader;
import org.concord.sensor.device.impl.AbstractSensorDevice;
import org.concord.sensor.device.impl.SerialPortParams;
import org.concord.sensor.impl.ExperimentConfigImpl;
import org.concord.sensor.impl.Range;
import org.concord.sensor.pasco.datasheet.ByteBufferStreamReversed;
import org.concord.sensor.pasco.datasheet.PasportSensorDataSheet;
import org.concord.sensor.pasco.datasheet.PasportSensorMeasurement;
import org.concord.sensor.pasco.jna.PascoChannel;
import org.concord.sensor.pasco.jna.PascoDevice;
import org.concord.sensor.pasco.jna.PascoException;
import org.concord.sensor.pasco.jna.PascoLibrary;

public class PascoUsbSensorDevice extends AbstractSensorDevice {
	private static final Logger logger = Logger
		.getLogger(PascoUsbSensorDevice.class.getCanonicalName());
	private PascoLibrary library;
	private boolean shutdownHookRegistered;
	private String errorMessage;
	private PascoDevice device;
	private PascoSensorManager manager = new PascoSensorManager();
	private String deviceName = "USB";

	public PascoUsbSensorDevice() {
		deviceLabel = "PS";
		
		if (library == null) {
			library = PascoLibrary.getInstance();
			try {
				openInterface();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		
		if (! shutdownHookRegistered) {
			Runtime.getRuntime().addShutdownHook(new Thread(){
				public void run() {
					logger.finer("Closing Pasco USB Sensor Device.");
					
					// Try to make sure the usb is closed
					// FIXME need to also stop sampling if it is started
					library.stop();
					library.delete();
				}
			});
			shutdownHookRegistered = true;
		}
		logger.finer("New PascoUsbSensorDevice created.");
	}

	private void openInterface() throws IOException, InterruptedException {
		logger.finer("Open interface");
		library.initLibrary();
		library.init();
		library.start();
        logger.finer("  opened");
	}

	@Override
	protected SerialPortParams getSerialPortParams() {
		// not using serial port
		return null;
	}

	@Override
	protected boolean initializeOpenPort(String portName) {
		// this isn't used because we override the open method instead
		return false;
	}
	
	/**
	 * Because we are using a api that abstracts the usb and/or serial port connection
	 * we override this to initialize the api instead of opening the port. 
	 * 
	 * 
	 * @see org.concord.sensor.device.impl.AbstractSensorDevice#openPort()
	 */
	@Override
	public void open(String portParams) {
		if(library == null){
			return;
		}
		
		try {
			PascoDevice[] devices = null;
			for(int i=0; i<50; i++){
				devices = library.getDevices();
				if(devices.length > 0){
					break;
				}
				Thread.sleep(100);
			}
			if(devices.length == 0){
				errorMessage = "Can't find an attached Pasco USB device";
				return;
			}

			// right now we just will take the first device found
			device = devices[0];
			
			deviceName = device.getDeviceName();
		} catch (PascoException e) {
			e.printStackTrace();
			errorMessage = "Error looking for attached Pasco USB device:\n" + 
			  "  " + e.getMessage();
		} catch (InterruptedException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	
	/**
	 * We don't have a port, but openPort is called by the auto configure code.
	 * 
	 * @see org.concord.sensor.device.impl.AbstractSensorDevice#openPort()
	 */
	protected boolean openPort()
	{
		return device != null;
	}
		
	public boolean canDetectSensors() {
		return true;
	}

	public String getDeviceName() {
		// FIXME the Pasco SDK should be updated to provide information about the attached device
		// so we can report which device we have found
		return deviceName;
	}

	public String getVendorName() {
		return "Pasco";
	}

	@Override
	public boolean isAttached() {
		if(device == null){
			return false;
		}
		
		// FIXME we should use library.getDevices here instead
		try {
			device.getChannels();
		} catch (PascoException e) {
			return false;
		}
		return true;
	}

	public ExperimentConfig getCurrentConfig() {
		// go through datasheet measurements to see which 
		// ones are visible to the user and add those
		// to a an experiment config we create here
	    ExperimentConfigImpl expConfig = new ExperimentConfigImpl();

		expConfig.setDeviceName(getVendorName() + " " + getDeviceName());

	    try {
			PascoChannel[] channels = device.getChannels();
			ArrayList<PasportSensor> sensorConfigList = new ArrayList<PasportSensor>();
			
			// TODO see about properly reseting the device
			manager.clearSensors();
			
			for (PascoChannel channel : channels) {
				if(!channel.getExist()){
					// sensor is not attached to this channel
					continue;
				}

				if(!channel.getSensorDetected()){
					// no probe is attached to the sensor on this channel
					continue;
				}
				
				byte [] dataSheetBuf = new byte[channel.getSensorDataSheetSize()];
				
				// In other code we handled issues with the datasheet not reading correctly
				// by stoping the device, and reading as many bytes as are available before requesting it again
				channel.readSensorDataSheet(dataSheetBuf, dataSheetBuf.length);
				PasportSensorDataSheet dataSheet = new PasportSensorDataSheet(new ByteBufferStreamReversed(dataSheetBuf, 0, dataSheetBuf.length));
				manager.addSensor(dataSheet, channel);
				PasportSensorMeasurement[] measurements = dataSheet.getMeasurements();
				for(PasportSensorMeasurement measurement: measurements){
			    	if(!measurement.isVisible()){
			    		continue;
			    	}
			    	
			    	// FIXME this ought to check if if the probe is attached to the channel that is 
			    	// the basis of this measurement.  The first step to that is to add the 
			    	// measurement validity methods to PasportSensorMeasurement
			    	
			    	sensorConfigList.add(new PasportSensor(channel, measurement));
			    }
			}
		    SensorConfig [] sensorConfigArr = sensorConfigList.toArray(new SensorConfig[0]);
		    expConfig.setSensorConfigs(sensorConfigArr);

		    float minDefaultPeriod = manager.getMinDefaultPeriod();
		    if(Float.isNaN(minDefaultPeriod)){
		    	expConfig.setValid(false);
		    }
		    expConfig.setPeriod(minDefaultPeriod);
		    expConfig.setPeriodRange(new Range(manager.getMinPeriod(), manager.getMaxPeriod()));
		} catch (PascoException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	    	    
	    return expConfig;
	}

	@Override
	protected boolean supportsRawSensorValues() {
		return false;
	}
	
	@Override
	protected SensorConfig createSensorConfig(int type, int requestPort) 
	{
		return null;
	}
	
	public boolean start() {
		try {
			manager.clearMeasurements();
			
			// collect the channels that are part of the currentConfig
			SensorConfig[] sensorConfigs = currentConfig.getSensorConfigs();
			for(SensorConfig config: sensorConfigs){
				PasportSensor sensor = (PasportSensor)config;
				manager.addMeasurement(sensor.getMeasurement(), sensor.getChannel());
			}
			manager.startChannels(currentConfig.getPeriod());
		} catch (PascoException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		return true;
	}

	public String getErrorMessage(int error) {
		if(errorMessage == null){
			return "Unkown Error";
		}
		
		return errorMessage;
	}

	public ExperimentConfig configure(ExperimentRequest request) {
		// FIXME we ought to recalculate the period based on the requested sensors
		// currently the period is based on all of the attached sensors not just the
		// requested ones
		return autoIdConfigure(request);
	}

	public void stop(boolean wasRunning) {
		manager.stopChannels();
	}

	public int read(float[] values, int offset, int nextSampleOffset,
			DeviceReader reader) {
		
		try {
			return manager.read(values, offset, nextSampleOffset);
		} catch (PascoException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			return -1;
		}
	}
	
	@Override
	public void close() {
		// Try to make sure the usb is closed
		// FIXME need to also stop sampling if it is started
		library.stop();
		library.delete();
	}

}
