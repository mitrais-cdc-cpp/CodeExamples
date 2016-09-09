#include "../../inc/scenario1/staff.hpp"

using namespace scenario1;

staff::staff(std::string staffId, std::time_t joinDate)
{
	this->staffId = staffId;
	this->joinDate = joinDate;
}

staff::~staff()
{

}

void staff::showStaffId()
{
	std::cout << "StaffId : " << this->staffId << std::endl;
}

void staff::showJoinDate()
{
	std::cout << "JoinDate : " << std::asctime(std::gmtime(&this->joinDate)) << std::endl;
}
