package org.concord.sensor.labprousb.jna;

import com.sun.jna.ptr.IntByReference;
import com.sun.jna.ptr.ShortByReference;

public class LabProUSBImpl implements LabProUSB {
	private LabProUSBJNA lpusb;

	public LabProUSBImpl(LabProUSBJNA lpusb) {
		this.lpusb = lpusb;
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#open()
	 */
	public short open() {
		return lpusb.open();
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#close()
	 */
	public short close() {
		return lpusb.close();
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#isOpen()
	 */
	public short isOpen() {
		return lpusb.isOpen();
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#getAvailableBytes()
	 */
	public int getAvailableBytes() {
		return lpusb.getAvailableBytes();
	}

	/* (non-Javadoc)
	 * @Override
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#readBytes(long, byte[])
	 */
	public int readBytes(int numBytes, byte[] buffer) {
		IntByReference intRef = new IntByReference(numBytes);
		short ret = lpusb.readBytes(intRef, buffer);
		if (ret >= 0) {
			return intRef.getValue();
		}
		return ret;
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#writeBytes(short, byte[])
	 */
	public short writeBytes(short numBytes, byte[] buffer) {
		ShortByReference shortRef = new ShortByReference(numBytes);
		short ret = lpusb.writeBytes(shortRef, buffer);
		if (ret >= 0) {
			return shortRef.getValue();
		}
		return ret;
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#clearInputs(short)
	 */
	public short clearInputs(short ignored) {
		return lpusb.clearInputs(ignored);
	}

	/* (non-Javadoc)
	 * @see org.concord.sensor.labprousb.jna.ILabProUSB#setNumChannelsAndModes(int, short, short)
	 */
	public short setNumChannelsAndModes(int numChannels, short binaryMode, short realTime) {
		return lpusb.setNumChannelsAndModes(numChannels, binaryMode, realTime);
	}
}
