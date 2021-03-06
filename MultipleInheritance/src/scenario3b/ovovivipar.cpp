#include "../../inc/scenario3b/ovovivipar.hpp"

using namespace scenario3b;

ovovivipar::ovovivipar(std::string name)
	:animal(name)
	,ovipar(name)
	,vivipar(name)
{
	/*
	 note:
	 1. all the parent classes are called above.
	 2. Absence of calling the top parent (animal) will throw the following error:
	 error: no matching function for call to ‘scenario3b::animal::animal()’
	 ,ovipar(name)
	             ^
	  */
}

ovovivipar::~ovovivipar()
{

}
