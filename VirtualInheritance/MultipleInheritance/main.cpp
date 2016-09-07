#include <iostream>

/**
 * USB Device
 */
class USBDevice
{
private:
    long m_lID;
 
public:
    /**
     * Default Constructor
     *
     * @param lID
     */
    USBDevice(long lID)
        : m_lID(lID)
    {
    }
 
    /**
     * get Id
     *
     * @return id
     */
    long GetID()
    {
    	return m_lID;
    }
};
 
/**
 * Network Device class
 */
class NetworkDevice
{
private:
    long m_lID;
 
public:
    /**
     * Default constructor
     *
     * @param lID
     */
    NetworkDevice(long lID)
        : m_lID(lID)
    {
    }
 
    /**
     * Get Id function
     *
     * @return Id
     */
    long GetID()
    {
    	return m_lID;
    }
};
 
/**
 * Wireless Adapter class derived from UsbDevice and NetworkDevice
 */
class WirelessAdaptor: public USBDevice, public NetworkDevice
{
public:
	/**
	 * Default constructor
	 *
	 * @param lUSBID
	 * @param lNetworkID
	 */
    WirelessAdaptor(long lUSBID, long lNetworkID)
        : USBDevice(lUSBID), NetworkDevice(lNetworkID)
    {
    }
};

/**
 * Main Function
 *
 * @return int
 */
int main()
{
    WirelessAdaptor c54G(5442, 181742);
    //std::cout << c54G.GetID(); // Which GetID() do we call?
    std::cout << c54G.USBDevice::GetID() << std::endl;;
 
    return 0;
}
