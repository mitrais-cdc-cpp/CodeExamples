/*
 * Foo.h
 *
 *  Created on: Jul 29, 2016
 *      Author: developer
 */

#ifndef INC_TEXTWRITTER_H_
#define INC_TEXTWRITTER_H_

#include <cstring>
#include <utility>

namespace Mitrais
{
	/**
	 * A Template class for text writter
	 */
	template<class TDBConnector>
	class TextWritter
	{
		public:

			/**
			 * Default constructor
			 * @param connector: A pointer for database connector class
			 */
			TextWritter(TDBConnector connector)
			: _connector( new TDBConnector(connector))
			{
			}

			/**
			 * Copy constructor
			 * @param other
			 */
			TextWritter(const TextWritter & other)
			: _connector(new TDBConnector(*(other._connector)))
			{
			}

			/**
			 * Assignment operator
			 * @param other
			 * @return this object
			 */
			const TextWritter operator = (const TextWritter & other)
			{
				TextWritter<TDBConnector> temp(other);
				temp.swap(*this);

				return *this;
			}

			/**
			 * Default destructor
			 */
			virtual ~TextWritter()
			{
				delete _connector;
			}

			/**
			 * Move copy constructor
			 * @param other
			 */
			TextWritter(TextWritter && other)
			: _connector(other._connector)
			{
				other._connector = nullptr;
			}

			/**
			 * Move assignment operator
			 * @param other
			 * @return
			 */
			TextWritter & operator = (TextWritter && other)
			{
				TextWritter<TDBConnector> temp(other);
				temp.swap(*this);

				return *this;
			}

			/**
			 * Write content to database
			 * @param content
			 */
			void writeContentToDB(std::string & content)
			{
				_connector->inserContent(content);
			}

			/**
			 * Swap method
			 * @param writer: Address of writer object
			 */
			void swap(TextWritter & writer) throw()
			{
				std::swap(this->_connector, writer._connector);
			}

		private:

			/**
			 * The pointer of database connector
			 */
			TDBConnector* _connector = nullptr;

	};
}


#endif /* INC_TEXTWRITTER_H_ */
