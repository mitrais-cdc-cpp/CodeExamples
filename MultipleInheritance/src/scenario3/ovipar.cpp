#include "../../inc/scenario3/ovipar.hpp"

using namespace scenario3;

ovipar::ovipar(std::string name) : animal(name)
{
	this->type = "oviparous is a kind of zoo producing young by means of eggs";
}

void ovipar::produceEgg()
{
	std::cout << "I'm producing eggs..." << std::endl;
}

ovipar::~ovipar()
{

}
