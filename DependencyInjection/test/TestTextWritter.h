/*
 * TestTexWritter.h
 *
 *  Created on: Aug 3, 2016
 *      Author: developer
 */

#ifndef TEST_TESTTEXTWRITTER_H_
#define TEST_TESTTEXTWRITTER_H_


#include <cppunit/TestFixture.h>
#include <cppunit/extensions/HelperMacros.h>
#include "../inc/DBConnector.h"
#include "../inc/TextWritter.h"

using namespace Mitrais;
class TestTextWritter: public CppUnit::TestFixture
{
	public:
		CPPUNIT_TEST_SUITE(TestTextWritter);
		CPPUNIT_TEST(testInsertContentSuccess);
		CPPUNIT_TEST(testInsertContentFail);
		CPPUNIT_TEST_SUITE_END();
	private:
		void testInsertContentSuccess();
		void testInsertContentFail();
};

CPPUNIT_TEST_SUITE_REGISTRATION( TestTextWritter );
#endif /* TEST_TESTTEXTWRITTER_H_ */
