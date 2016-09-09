#include <iostream>

class PoweredDevice
{
public:
    PoweredDevice(int nPower)
    {
		std::cout << "PoweredDevice: " << nPower << std::endl;
    }
};
 
class Scanner: virtual public PoweredDevice
{
public:
    Scanner(int nScanner, int nPower)
        : PoweredDevice(nPower)
    {
		std::cout << "Scanner: " << nScanner << std::endl;
    }
};
 
class Printer: virtual public PoweredDevice
{
public:
    Printer(int nPrinter, int nPower)
        : PoweredDevice(nPower)
    {
		std::cout << "Printer: " << nPrinter << std::endl;
    }
};
 
class Copier: public Scanner, public Printer
{
public:
    Copier(int nScanner, int nPrinter, int nPower)
        : Scanner(nScanner, nPower), Printer(nPrinter, nPower), PoweredDevice(nPower)
    {
    }
};

int main()
{
    Copier cCopier(1, 2, 3);
}