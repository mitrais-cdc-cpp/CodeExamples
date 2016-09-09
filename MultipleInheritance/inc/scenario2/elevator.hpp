
#ifndef INC_SCENARIO2_ELEVATOR_HPP_
#define INC_SCENARIO2_ELEVATOR_HPP_

#include <iostream>

namespace scenario2
{
	class elevator
	{
		public:
			elevator(int ladderHeight, long fuelCapacity);
			virtual ~elevator();

			void showladderHeight();
			void showFuelCapacity();

		protected:
			int ladderHeight;
			long fuelCapacity;

	};
}

#endif /* INC_SCENARIO2_ELEVATOR_HPP_ */
