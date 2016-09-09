
#ifndef INC_SCENARIO2_TRUCK_HPP_
#define INC_SCENARIO2_TRUCK_HPP_

#include <iostream>

namespace scenario2
{
	class truck
	{
		public:
			truck(std::string plateNumber, long fuelCapacity);
			virtual ~truck();

			void showPlateNumber();
			void showFuelCapacity();

		protected:
			std::string plateNumber;
			long fuelCapacity;

	};
}

#endif /* INC_SCENARIO2_TRUCK_HPP_ */
