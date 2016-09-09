#include "../../inc/scenario1/frontOfficer.hpp"

using namespace scenario1;

frontOfficer::frontOfficer(std::string id, std::string name, std::string staffId, std::time_t joinDate)
	: individual(id, name)
	, staff(staffId, joinDate)
{
}

frontOfficer::~frontOfficer()
{

}
