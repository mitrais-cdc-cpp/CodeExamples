/*
 * Foo.h
 *
 *  Created on: Jul 29, 2016
 *      Author: developer
 */

#ifndef INC_TEXTWRITTER_H_
#define INC_TEXTWRITTER_H_

#include <cstring>

namespace Mitrais
{
	template<class TDBConnector>
	class TextWritter
	{
		public:
<<<<<<< HEAD
			TextWritter(TDBConnector & connector)
=======
			TextWritter(TDBConnector &connector)
>>>>>>> 357ec8ef534cd7dba302b97d4b10868e2d36940b
			: _connector(connector)
			{
			}

<<<<<<< HEAD
			void writeContentToDB(std::string & content)
=======
			void writeContentToDB(std::string &content)
>>>>>>> 357ec8ef534cd7dba302b97d4b10868e2d36940b
			{
				_connector.inserContent(content);
			}

		private:
<<<<<<< HEAD
			TDBConnector & _connector;
=======
			TDBConnector _connector;
>>>>>>> 357ec8ef534cd7dba302b97d4b10868e2d36940b
	};
}


#endif /* INC_TEXTWRITTER_H_ */
