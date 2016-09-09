#include "../../inc/scenario2/truck.hpp"

using namespace scenario2;

truck::truck(std::string plateNumber, long fuelCapacity)
{
	this->plateNumber = plateNumber;
	this->fuelCapacity = fuelCapacity;
}

truck::~truck()
{

}

void truck::showPlateNumber()
{
	std::cout << "Plate Number: " << this->plateNumber << std::endl;
}

void truck::showFuelCapacity()
{
	std::cout << "Truck Fuel Capacity: " << this->fuelCapacity << std::endl;
}
