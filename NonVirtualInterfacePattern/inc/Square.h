/*
 * Square.h
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#include "Shape.h"

namespace Mitrais
{
	/**
	 * The square class, this class is derived form Shape class
	 */
	class Square : public Shape
	{
		public:
			/**
			 * Default constructor
			 * @param width: The rectangle width
			 */
			Square(double width);

			/**
			 * Default destructor
			 */
			~Square();

		private:
			/**
			 * The square width
			 */
			double _width;

			/**
			 * The method to calculate the square area.
			 * This method override the getArea method from the Shape class
			 * @return The square area
			 */
			double getArea();

			/**
			 * The function to get the type of the shape.
			 * This method override the getType method from the Shape class
			 * @return The type of shape
			 */
			std::string getType();
	};
}
