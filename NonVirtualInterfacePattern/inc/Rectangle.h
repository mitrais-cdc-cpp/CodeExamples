/*
 * Rectangle.h
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#ifndef INC_RECTANGLE_H_
#define INC_RECTANGLE_H_

#include "Shape.h"

using namespace std;

namespace Mitrais
{
	/**
	 * The rectangle class, this class is derived form Shape class
	 */
	class Rectangle : public Shape
	{
		public:

			/**
			 * Default constructor
			 * @param width: The rectangle width
			 * @param height: The rectangle height
			 */
			Rectangle(double width, double height);

			/**
			 * Default destructor
			 */
			~Rectangle();

		private:
			/**
			 * The rectangle width
			 */
			double _width;

			/**
			 * The rectangle height
			 */
			double _height;

			/**
			 * The method to calculate the rectangle area.
			 * This method override the getArea method from the Shape class
			 * @return The rectangle area
			 */
			double getArea();
	};
}


#endif /* INC_RECTANGLE_H_ */
