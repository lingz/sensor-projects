package org.concord.sensor.cc;

import org.concord.sensor.*;
import org.concord.waba.extra.util.*;

import org.concord.framework.data.stream.*;

public class CCThermalCouple extends Sensor
	implements CCModes
{

	float  			[]tempData 		= new float[3];
	int  			[]tempIntData 	= new int[3];
	float  			dtChannel = 0.0f;
	public final static int		CELSIUS_TEMP_OUT = 0;
	public final static int		FAHRENHEIT_TEMP_OUT = 1;
	public final static int		KELVIN_TEMP_OUT = 2;

	PropObject modeProp = new PropObject("Output Mode", "Mode", PROP_MODE, 
										 tempModes, CELSIUS_TEMP_OUT);

	int				outputMode = CELSIUS_TEMP_OUT;
	public final static String	[]tempModes =  {"C","F","K"};

	float AC = 17.084f;
	float BC = -0.25863f;
	float CC = 0.011012f;
	float DC = 10f;
	float EC = -50f;
	float FC = 0.0f;

	CCThermalCouple(boolean init, short type, SensorProducer p)
	{
		super(init, type, p);

		interfaceMode = CCInterface2.getMode(PORT_A, A2D_24_MODE);

		activeChannels = 2;
		defQuantityName = "Temperature";

		dDesc.setChannelPerSample(1);
		dDesc.setDt(0.0f);
		dDesc.setDataOffset(0);
		dEvent.setDataDescription(dDesc);

		dEvent.setNumSamples(1);
		dEvent.setData(tempData);
		dEvent.setIntData(tempIntData);

		addProperty(modeProp);

		if(init){
			calibrationDesc = new CalibrationDesc();
			calibrationDesc.addCalibrationParam(new CalibrationParam(0,FC));			
		}
	}

	public String getUnit()
	{
		int oMode = modeProp.getIndex();
		
		switch(oMode){
		case FAHRENHEIT_TEMP_OUT:
			unit = "F";
			break;
		case KELVIN_TEMP_OUT:
			unit = "K";
			break;
		default:
		case CELSIUS_TEMP_OUT:
			unit = "C";
			break;
		}	   

		return unit;
	}

	public int getPrecision(){return -1; }

	public Object getInterfaceMode()
	{
		return interfaceMode;
	}

    public boolean startSampling(DataEvent e)
	{
		DataStreamDescription eDesc = 
			e.getDataDescription();

		dEvent.type = e.type;
		dDesc.setDt(eDesc.getDt());
		dEvent.setNumSamples(1);
		dDesc.setTuneValue(eDesc.getTuneValue());
				
		//		dDesc.setIntChPerSample(2);

		return super.startSampling(dEvent);
    }

	public boolean dataArrived(DataEvent e)
	{
		DataStreamDescription eDesc = e.getDataDescription();

		dEvent.type = e.type;
		int nOffset = eDesc.getDataOffset();
		int nextSampleOff = eDesc.getNextSampleOffset();

		int ndata = e.getNumSamples()*nextSampleOff;
		if(ndata == 0) return false;
		
		int[] data = e.getIntData();
		float tuneValue = dDesc.getTuneValue();
		for(int i = 0; i < ndata; i+=nextSampleOff){
			float mV = (float)data[nOffset+i]*tuneValue;
			float ch2 = (float)data[nOffset+i+1]*tuneValue;
			float lastColdJunct = (ch2 / DC) + EC;
			tempData[0] = mV * (AC + mV * (BC + mV * CC)) + lastColdJunct;
			tempData[0] += FC;
			tempIntData[0] = data[nOffset+i];
			tempIntData[1] = data[nOffset+i+1];
			switch(outputMode){
			case FAHRENHEIT_TEMP_OUT:
				tempData[0] = tempData[0]*1.8f + 32f;
				break;
			case KELVIN_TEMP_OUT:
				tempData[0] += 273.15f;
				break;
			default:
				break;
			}
			super.dataArrived(dEvent);
		}
		return true;
	}

	public void  calibrationDone(float []row1,float []row2,float []calibrated)
	{
		if(row1 == null || calibrated == null) return;
		float ch1 = row1[0];
		float ch2 = row2[0];
		float lastColdJunct = (ch2 / DC) + EC;
		float mV = ch1;
		float mV2 = mV * mV;
		float mV3 = mV2 * mV;
		float trueValue = mV * AC + mV2 * BC + mV3 * CC + lastColdJunct;
		float userValue = calibrated[0];
		switch(outputMode){
		case FAHRENHEIT_TEMP_OUT:
			userValue = (userValue - 32f)/1.8f;
			break;
		case KELVIN_TEMP_OUT:
			userValue -= 273.15f;
			break;
		default:
			break;
		}
		FC = userValue - trueValue;
		if(calibrationDesc != null){
			CalibrationParam p = calibrationDesc.getCalibrationParam(0);
			if(p != null) p.setValue(FC);
		}
	}
	public void calibrationDescReady(){
		if(calibrationDesc == null) return;
		CalibrationParam p = calibrationDesc.getCalibrationParam(0);
		if(p == null || !p.isValid()) return;
		FC = p.getValue();
	}
}