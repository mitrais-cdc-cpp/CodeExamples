#include "../../inc/scenario2/fireEngine.hpp"

using namespace scenario2;

fireEngine::fireEngine(std::string plateNumber, long fuelCapacity, int ladderHeight)
	:truck(plateNumber, fuelCapacity)
	,elevator(ladderHeight, fuelCapacity)
{

}

fireEngine::~fireEngine()
{

}
