/*
 * Triangle.h
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#ifndef INC_TRIANGLE_H_
#define INC_TRIANGLE_H_

#include "Shape.h"

using namespace std;
namespace Mitrais
{
	/**
	 * The Triangle class, this class is derived form Shape class
	 */
	class Triangle : public Shape
	{
		public:
			/**
			 * The default constructor
			 * @param width: The triangle width
			 * @param height: The triangle height
			 */
			Triangle(double width, double height);

			/**
			 * The default destructor
			 */
			~Triangle();

		private:
			/**
			 * The triangle width
			 */
			double _width;

			/**
			 * The triangle height
			 */
			double _height;

			/**
			 * The function to get the type of the shape.
			 * This method override the getType method from the Shape class
			 * @return The type of shape
			 */
			std::string getType();

			/**
			 * The method to calculate the triangle area.
			 * This method override the getArea method from the Shape class
			 * @return The triangle area
			 */
			virtual double getArea();
	};
}


#endif /* INC_TRIANGLE_H_ */
