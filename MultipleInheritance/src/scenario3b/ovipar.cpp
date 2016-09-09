#include "../../inc/scenario3b/ovipar.hpp"

using namespace scenario3b;

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
