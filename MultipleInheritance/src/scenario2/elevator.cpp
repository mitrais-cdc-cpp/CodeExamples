#include "../../inc/scenario2/elevator.hpp"

using namespace scenario2;

elevator::elevator(int ladderHeight, long fuelCapacity)
{
	this->ladderHeight = ladderHeight;
	this->fuelCapacity = fuelCapacity;
}

elevator::~elevator()
{

}

void elevator::showladderHeight()
{
	std::cout << "Ladder Height: " << this->ladderHeight << std::endl;
}

void elevator::showFuelCapacity()
{
	std::cout << "Elevator Fuel Capacity: " << this->fuelCapacity << std::endl;
}
