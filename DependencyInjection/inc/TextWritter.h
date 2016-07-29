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
			TextWritter(TDBConnector &connector)
			: _connector(connector)
			{
			}

			void writeContentToDB(std::string &content)
			{
				_connector.inserContent(content);
			}

		private:
			TDBConnector _connector;
	};
}


#endif /* INC_TEXTWRITTER_H_ */
