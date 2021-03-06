#ifndef INC_SCENARIO1_STAFF_HPP_
#define INC_SCENARIO1_STAFF_HPP_

#include <iostream>
#include <ctime>

namespace scenario1
{
	class staff
	{
		public:
			staff(std::string staffId, std::time_t joinDate);
			virtual ~staff();
			void showStaffId();
			void showJoinDate();

		protected:
			std::string staffId;
			std::time_t joinDate;
	};
}

#endif /* INC_SCENARIO1_STAFF_HPP_ */
