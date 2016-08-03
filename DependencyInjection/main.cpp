/*============================================================================
* Name        : Dependency Injection in C++
* Author      : I Komang Suhendra Eka Putra
* Version     :
* Copyright   :
* Description : Implementation of Dependency Injection in C++.
* This project created for C++ Bootcamp Training in Mitrais.
==============================================================================*/

#include <iostream>
#include <string>
#include "inc/DBConnector.h"
#include "inc/TextWritter.h"

using namespace Mitrais;
int main(int argc, char* argv[])
{
	// Create the connector object connectorA and connectorB
	DBConnector connectorA("localhost", 8001, "DbContent");
	DBConnector connectorB("175.19.14.151", 8009, "DbContent");

	// Create the writer object and inject the connectorA object into it
	TextWritter<DBConnector> writer1(connectorA);

	// Try to call method writeContentToDB from writer1
	std::string content1("Test Content 1, written by writer 1");
	writer1.writeContentToDB(content1);

	// Try to create other writer object using copy constructor from writer1
	TextWritter<DBConnector> writer2(writer1);

	// Try to call method writeContentToDB from writer2
	std::string content2("Test Content 2, written by writer 2");
	writer2.writeContentToDB(content2);

	// Create the writer3 object and inject connectorB into it
	TextWritter<DBConnector> writer3(connectorB);

	// Try to call method writeContentToDB from writer3
	std::string content3("Test Content 3, written by writer 3");
	writer3.writeContentToDB(content3);

	// Assign writer3 to writer2 using assignment operator
	writer3 = writer2;

	// Try to call method writeContentToDB from writer3
	std::string content4("");
	writer3.writeContentToDB(content4);
	return 0;
}

