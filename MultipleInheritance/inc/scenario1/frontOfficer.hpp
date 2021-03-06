
#ifndef INC_SCENARIO1_FRONTOFFICER_HPP_
#define INC_SCENARIO1_FRONTOFFICER_HPP_

#include <iostream>
#include <ctime>

#include "individual.hpp"
#include "staff.hpp"

namespace scenario1
{
	class frontOfficer final: public individual, public staff
	{
		public:
			frontOfficer(std::string id, std::string name, std::string staffId, std::time_t joinDate);
			~frontOfficer();
	};
}

#endif /* INC_SCENARIO1_FRONTOFFICER_HPP_ */
