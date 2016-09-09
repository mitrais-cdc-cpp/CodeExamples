#include "../../inc/scenario3b/vivipar.hpp"

using namespace scenario3b;

vivipar::vivipar(std::string name) : animal(name)
{
	this->type = "viviparous is kind of zoo bringing forth live young developed inside the body of the parent.";
}

void vivipar::deliverBaby()
{
	std::cout << "I'm delivering a baby..." << std::endl;
}

vivipar::~vivipar()
{

}
