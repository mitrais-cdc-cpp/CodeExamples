/*
 * DBConnector.cpp
 *
 *  Created on: Jul 29, 2016
 *      Author: developer
 */


#include "../inc/DBConnector.h"

namespace Mitrais
{
	DBConnector::DBConnector(const std::string &dbHost, const int &dbPort, const std::string &dbName)
	: _dbHost(dbHost), _dbPort(dbPort), _dbName(dbName)
	{
	}

	DBConnector::~DBConnector()
	{
	}

	void DBConnector::inserContent(std::string &content)
	{
		std::cout << "Content: " << content << "; has been saved to: " << _dbName << std::endl;
	}
}

