/*
 * Square.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#include "../inc/Square.h"

using namespace std;
namespace Mitrais
{
	/**
	 * Default constructor
	 * @param width: The rectangle width
	 */
	Square::Square(double width)
		: _width(width)
	{
	}

	/**
	 * Default destructor
	 */
	Square::~Square()
	{
	}

	/**
	 * The function to get the type of the shape.
	 * This method override the getType method from the Shape class
	 * @return The type of shape
	 */
	std::string Square::getType()
	{
		return "Square";
	}

	/**
	 * The method to calculate the square area.
	 * This method override the getArea method from the Shape class
	 * @return The square area
	 */
	double Square::getArea()
	{
		return _width * _width;
	}
}
