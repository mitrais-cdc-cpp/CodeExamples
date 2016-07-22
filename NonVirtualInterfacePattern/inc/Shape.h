/*
 * Shape.h
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#ifndef INC_SHAPE_H_
#define INC_SHAPE_H_

#include <iostream>
#include <cstring>

using namespace std;

namespace Mitrais
{
	/**
	 * The base class for shape
	 */
	class Shape
	{
		public:
			/**
			 * Default constructor
			 */
			Shape();

			/**
			 * Default destructor
			 */
			virtual ~Shape();

			/**
			 * This function will print the area of particular shape.
			 * The non virtual function. This public method cannot be overridden in child class.
			 * The public methods call private virtual members in the base class,
			 * which contain core functionality that may be overridden in child class.
			 */
			void printArea();

		private:
			/**
			 * The function to get the area of particular shape.
			 * This must be overridden in the child class.
			 * @return The shape area
			 */
			virtual double getArea() = 0;

			/**
			 * The function to get the type of the shape.
			 * The base class will give the default value,
			 * but the child class can override this function
			 * @return The type of shape
			 */
			virtual std::string getType();
	};
}



#endif /* INC_SHAPE_H_ */
