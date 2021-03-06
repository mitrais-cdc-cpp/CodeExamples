#ifndef INC_SCENARIO2_FIREENGINE_HPP_
#define INC_SCENARIO2_FIREENGINE_HPP_

#include "truck.hpp"
#include "elevator.hpp"

namespace scenario2
{
	class fireEngine final: public truck, public elevator
	{
		public:
			fireEngine(std::string plateNumber, long fuelCapacity, int ladderHeight);
			~fireEngine();
	};
}

#endif /* INC_SCENARIO2_FIREENGINE_HPP_ */
