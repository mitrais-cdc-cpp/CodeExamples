/*
 * DBConnector.h
 *
 *  Created on: Jul 29, 2016
 *      Author: developer
 */

#ifndef INC_DBCONNECTOR_H_
#define INC_DBCONNECTOR_H_

#include <iostream>
#include <string>

using namespace std;
namespace Mitrais
{
	/**
	 * A sample class for database connector
	 */
	class DBConnector
	{
		public:
			/**
			 * Default constructor
			 * @param dbHost: Database host
			 * @param dbPort: Database port
			 * @param dbName: Database name
			 */
			DBConnector(const std::string &dbHost, const int &dbPort, const std::string &dbName);

			/**
			 * Default destructor
			 */
			~DBConnector();

			/**
			 * A method to insert content
			 * @param content: string content
			 */
			bool inserContent(std::string &content);

		private:
			/**
			 * Database host
			 */
			const std::string _dbHost;

			/**
			 * Database port
			 */
			const int _dbPort;

			/**
			 * Database name
			 */
			const std::string _dbName;
	};
}


#endif /* INC_DBCONNECTOR_H_ */
