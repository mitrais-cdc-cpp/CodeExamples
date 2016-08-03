/*
 * TestTextWritter.cpp
 *
 *  Created on: Aug 3, 2016
 *      Author: developer
 */

#include "TestTextWritter.h"

void TestTextWritter::testInsertContentSuccess()
{
	DBConnector connector("localhost", 8001, "DbContent");
	TextWritter<DBConnector> writer(connector);

	bool expected = true;
	std::string content = "Test Content 1";
	bool actual = writer.writeContentToDB(content);

	CPPUNIT_ASSERT(expected == actual);
}


void TestTextWritter::testInsertContentFail()
{
	DBConnector connector("127.0.0.1", 8001, "DbContent");
	TextWritter<DBConnector> writer(connector);

	bool expected = false;
	std::string content = "";
	bool actual = writer.writeContentToDB(content);

	CPPUNIT_ASSERT(expected == actual);
}
