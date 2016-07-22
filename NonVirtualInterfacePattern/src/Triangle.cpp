/*
 * Triangle.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#include "../inc/Triangle.h"

namespace Mitrais
{
	/**
	 * The default constructor
	 * @param width: The triangle width
	 * @param height: The triangle height
	 */
	Triangle::Triangle(double width, double height)
		: _width(width), _height(height)
	{
	}

	/**
	 * The default destructor
	 */
	Triangle::~Triangle()
	{
	}

	/**
	 * The function to get the type of the shape.
	 * This method override the getType method from the Shape class
	 * @return The type of shape
	 */
	std::string Triangle::getType()
	{
		return "Triangle";
	}

	/**
	 * The method to calculate the triangle area.
	 * This method override the getArea method from the Shape class
	 * @return The triangle area
	 */
	double Triangle::getArea()
	{
		return 0.5 * _width * _height;
	}
}
