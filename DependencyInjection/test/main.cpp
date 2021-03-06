#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include "TestTextWritter.h"

#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	CppUnit::TextUi::TestRunner runner;
	CppUnit::TestFactoryRegistry &registry = CppUnit::TestFactoryRegistry::getRegistry();

	runner.addTest( registry.makeTest() );
	bool wasSuccessful = runner.run();

	return 0;
}


