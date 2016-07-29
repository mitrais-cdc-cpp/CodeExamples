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
	DBConnector connector("localhost", 8001, "DbContent");

	TextWritter<DBConnector> writter(connector);

	std::string content1("Test Content 1");
	writter.writeContentToDB(content1);

	std::string content2("Test Content 2");
	writter.writeContentToDB(content2);

	return 0;
}

