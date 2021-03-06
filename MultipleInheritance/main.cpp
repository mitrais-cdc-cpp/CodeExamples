#include <iostream>

#include "inc/scenario1/individual.hpp"
#include "inc/scenario1/staff.hpp"
#include "inc/scenario1/frontOfficer.hpp"

#include "inc/scenario2/truck.hpp"
#include "inc/scenario2/elevator.hpp"
#include "inc/scenario2/fireEngine.hpp"

#include "inc/scenario3/ovipar.hpp"
#include "inc/scenario3/vivipar.hpp"
#include "inc/scenario3/ovovivipar.hpp"

#include "inc/scenario3b/ovipar.hpp"
#include "inc/scenario3b/vivipar.hpp"
#include "inc/scenario3b/ovovivipar.hpp"

void scenario1Sample()
{
	namespace s1 = scenario1;

	std::cout<< "Sample of multiple inheritance Scenario 1:" << std::endl << std::endl;

	s1::individual bob("i10", "Bob");
	bob.showId();
	bob.showName();
	std::cout<< std::endl;

	std::time_t joinDate = time(0);

	s1::staff john("s90", joinDate);
	john.showStaffId();
	john.showJoinDate();
	std::cout<< std::endl;

	s1::frontOfficer fo("i10", "Bob", "s90", joinDate);
	fo.showId();
	fo.showName();
	fo.showStaffId();
	fo.showJoinDate();
	std::cout<< std::endl;
}

void scenario2Sample()
{
	namespace s2 = scenario2;

	std::cout<< "Sample of multiple inheritance Scenario 2:" << std::endl << std::endl;

	s2::truck tck("pn1", 50);
	tck.showPlateNumber();
	tck.showFuelCapacity();
	std::cout<< std::endl;

	s2::elevator elv(75, 25);
	elv.showladderHeight();
	elv.showFuelCapacity();
	std::cout<< std::endl;

	s2::fireEngine fre("fe1",50, 75);
	fre.showPlateNumber();
	fre.showladderHeight();

	// Problem1: ambiguity
	//fre.showFuelCapacity(); this line will throw error due to ambiguity on which method to call, either truck's or elevator's?

	// avoid ambiguity:
	fre.truck::showFuelCapacity();
	fre.elevator::showFuelCapacity();

	std::cout<< std::endl;
}

void scenario3Sample()
{
	namespace s3 = scenario3;

	std::cout<< "Sample of multiple inheritance Scenario 3:" << std::endl << std::endl;

	s3::animal an("something");
	an.showName();
	an.showType();
	an.makeMovement();
	std::cout<< std::endl;

	s3::vivipar tiger("TIGER");
	tiger.showName();
	tiger.showType();
	tiger.makeMovement();
	tiger.deliverBaby();
	std::cout<< std::endl;

	s3::ovipar duck("DUCK");
	duck.showName();
	duck.showType();
	duck.makeMovement();
	duck.produceEgg();
	std::cout<< std::endl;

	s3::ovovivipar shark("SHARK");

	// Problem: ambiguity
	shark.vivipar::showName();
	shark.vivipar::showType();
	shark.vivipar::makeMovement();
	shark.vivipar::deliverBaby();

	shark.ovipar::showName();
	shark.ovipar::showType();
	shark.ovipar::makeMovement();
	shark.ovipar::produceEgg();

	std::cout<< std::endl;
}

void scenario3bSample()
{
	namespace s3b = scenario3b;

	std::cout<< "Sample of multiple inheritance Scenario 3b:" << std::endl << std::endl;

	s3b::animal anb("something");
	anb.showName();
	anb.showType();
	anb.makeMovement();
	std::cout<< std::endl;

	s3b::vivipar tigerb("TIGER");
	tigerb.showName();
	tigerb.showType();
	tigerb.makeMovement();
	tigerb.deliverBaby();
	std::cout<< std::endl;

	s3b::ovipar duckb("DUCK");
	duckb.showName();
	duckb.showType();
	duckb.makeMovement();
	duckb.produceEgg();
	std::cout<< std::endl;


	s3b::ovovivipar sharkb("SHARK");

	// note: can call all the methods directly
	sharkb.showName();

	/* which method to call: is it the one belongs to ovipar or vivipar? How to drive it to be the explicit one?
	 answer: it will be the method of the class which the class is inherited last at the header file:
		- e.g. if it was defined like this class ovovivipar final: public vivipar, public ovipar ..the call will the one belongs to ovipar
		- e.g. if it was defined like this class ovovivipar final: public ovipar, public vivipar ..the call will the one belongs to vivipar
	*/

	sharkb.showType();

	sharkb.makeMovement();
	sharkb.deliverBaby();
	sharkb.produceEgg();

	std::cout<< std::endl;
}

int main()
{
	scenario1Sample();

	scenario2Sample();

	scenario3Sample();

	scenario3bSample();

	return 0;
}
