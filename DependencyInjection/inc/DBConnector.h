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
	class DBConnector
	{
		public:
			DBConnector(const std::string &dbHost, const int &dbPort, const std::string &dbName);
			~DBConnector();

			void inserContent(std::string &content);

		private:
			const std::string _dbHost;
			const int _dbPort;
			const std::string _dbName;
	};
}


#endif /* INC_DBCONNECTOR_H_ */
