/*
 * Created on Feb 16, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package org.concord.sensor.serial;

/**
 * @author scott
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class ByteBufferStream
{
    byte [] inBuf;
    int offset;
    int endOffset;
    boolean lowNibble = false;
    
    public static final float readFloat(byte [] inBuf, int offset)
    {
        int valueInt = ((0xFF & inBuf[offset]) << 24)
                | ((0xFF & inBuf[offset + 1]) << 16)
                | ((0xFF & inBuf[offset + 2]) << 8)
                | (0xFF & inBuf[offset + 3]);
        return Float.intBitsToFloat(valueInt);        
    }

    public static final int readUShort(byte [] inBuf, int offset)
    {
        int value =((inBuf[offset] & 0xFF) << 8) | 
        	(inBuf[offset+1] & 0xFF);
        return value;        
    }

    public static final short readShort(byte [] inBuf, int offset)
    {
        int value =((inBuf[offset]) << 8) | 
        	(inBuf[offset+1] & 0xFF);
        return (short)value;
    }

    public static final void writeULong(long value, byte [] buf, int offset)
    {
        buf[offset]   = (byte)((value & 0xFF000000) >> 24);
        buf[offset+1] = (byte)((value & 0x00FF0000) >> 16);
        buf[offset+2] = (byte)((value & 0x0000FF00) >>  8);
        buf[offset+3] = (byte)(value & 0x000000FF);        
    }
    
    public static final void writeUShort(int value, byte [] buf, int offset)    
    {
        buf[offset] = (byte)((value & 0x0000FF00) >>  8);
        buf[offset+1] = (byte)(value & 0x000000FF);        
    }

    public ByteBufferStream(byte [] buffer, int offset, int length)
    {
        inBuf = buffer;
        this.offset = offset;
        this.endOffset = offset+length;
    }
    
    public float readFloat()
    {
        if(lowNibble) {
            throw new RuntimeException("unread low nibble");
        }
        float value = readFloat(inBuf, offset);
        offset += 4;
        
        return value;
    }
    
    public int readUShort()
    {
        if(lowNibble) {
            throw new RuntimeException("unread low nibble");
        }
        int value = readUShort(inBuf, offset);
        offset += 2;

        return value;        
    }
    
    public int readUByte()
    {
        if(lowNibble) {
            throw new RuntimeException("unread low nibble");
        }
        int value = (inBuf[offset] & 0xFF);
        offset++;
        return value;        
    }    

    public int readUNibble()
    {
        int value;
        
        if(lowNibble){
            value = (inBuf[offset] & 0xF);
            offset++;
            lowNibble = false;
        } else {
            value = ((inBuf[offset] & 0xF0) >> 4);
            // don't increase offset just set lowNibble
            lowNibble = true;           
        }
        
        return value;
    }

    public String readCRTermString()
    {
        if(lowNibble) {
            throw new RuntimeException("unread low nibble");
        }
        String returnStr = "";
        while(offset < endOffset){
            byte currChar = inBuf[offset++];
            if(currChar == 0x0D)  break;

            returnStr += (char)currChar;
        }
        
        return returnStr;
    }
}