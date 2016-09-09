#include "../../inc/scenario1/individual.hpp"

using namespace scenario1;

individual::individual(std::string id, std::string name)
{
	this->id = id;
	this->name = name;
}

individual::~individual()
{

}

void individual::showId()
{
	std::cout << "Id : " << this->id << std::endl;
}

void individual::showName()
{
	std::cout << "Name : " << this->name << std::endl;
}

