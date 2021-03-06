#include "../../inc/scenario3/ovovivipar.hpp"

using namespace scenario3;


ovovivipar::ovovivipar(std::string name)
	:vivipar(name)
	,ovipar(name)
{
	/*
	note:
	1. need to call the direct parent classes only at the above definition
	2. calling the top parent class, i.e. :animal(name) will throw a compilation error as below
	error: type ‘scenario3::animal’ is not a direct base of ‘scenario3::ovovivipar’
	:animal(name)
	 ^
	*/
}

ovovivipar::~ovovivipar()
{

}
