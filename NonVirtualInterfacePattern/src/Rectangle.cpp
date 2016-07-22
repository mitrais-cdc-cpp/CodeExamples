/*
 * Rectangle.cpp
 *
 *  Created on: Jul 21, 2016
 *      Author: developer
 */

#include "../inc/Rectangle.h"

namespace Mitrais
{
	/**
	 * Default constructor
	 * @param width: The rectangle width
	 * @param height: The rectangle height
	 */
	Rectangle::Rectangle(double width, double height)
		: _width(width), _height(height)
	{
	}

	/**
	 * Default destructor
	 */
	Rectangle::~Rectangle()
	{
	}

	/**
	 * The method to calculate the rectangle area.
	 * This method override the getArea method from the Shape class
	 * @return The rectangle area
	 */
	double Rectangle::getArea()
	{
		return _width *_height;
	}
}


