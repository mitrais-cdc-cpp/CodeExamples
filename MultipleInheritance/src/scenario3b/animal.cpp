#include "../../inc/scenario3b/animal.hpp"

using namespace scenario3b;

animal::animal(std::string name)
{
	this->name = name;
	this->type = "animal";
}

animal::~animal()
{

}

void animal::showName()
{
	std::cout << "My name: " << this->name << std::endl;
}

void animal::showType()
{
	std::cout << "My type: " << this->type<< std::endl;
}

void animal::makeMovement()
{
	std::cout << "I'm moving..." << std::endl;
}
