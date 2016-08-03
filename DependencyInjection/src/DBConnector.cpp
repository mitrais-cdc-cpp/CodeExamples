/*
 * DBConnector.cpp
 *
 *  Created on: Jul 29, 2016
 *      Author: developer
 */


#include "../inc/DBConnector.h"

namespace Mitrais
{
	/**
	 * Default constructor
	 * @param dbHost: Database host
	 * @param dbPort: Database port
	 * @param dbName: Database name
	 */
	DBConnector::DBConnector(const std::string &dbHost, const int &dbPort, const std::string &dbName)
	: _dbHost(dbHost), _dbPort(dbPort), _dbName(dbName)
	{
	}

	/**
	 * Default destructor
	 */
	DBConnector::~DBConnector()
	{
	}

	bool DBConnector::inserContent(std::string &content)
	{
		bool status = false;
		std::string connectionString = _dbHost + ":" + std::to_string(_dbPort) + "/" + _dbName;
		std::cout << "Make connection to: " << connectionString << endl;
		if(content !="")
		{
			std::cout << content << "; has been successfully saved\n" << std::endl;
			status = true;
		}
		else
		{
			std::cout << "Failed to save the content" << std::endl;
		}

		return status;
	}
}

