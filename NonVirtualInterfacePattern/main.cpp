/*============================================================================
* Name        : Non Virtual Interface Pattern
* Author      : I Komang Suhendra Eka Putra
* Version     :
* Copyright   :
* Description : Implementation of Non Virtual Interface Pattern in C++.
* This project created for C++ Bootcamp Training in Mitrais.
==============================================================================*/

#include <iostream>
#include <memory>
#include "inc/Shape.h"
#include "inc/Square.h"
#include "inc/Rectangle.h"
#include "inc/Triangle.h"

using namespace std;
using namespace Mitrais;


int main(int argc, char* argv[])
{
	// Square
	shared_ptr<Shape> squarePtr = make_shared<Square>(3.0);
	squarePtr->printArea();

	// Rectangle
	shared_ptr<Shape> rectanglePtr = make_shared<Rectangle>(3.0, 4.0);
	rectanglePtr->printArea();

	// Triangle
	shared_ptr<Shape> trianglePtr = make_shared<Triangle>(3.0, 4.0);
	trianglePtr->printArea();

	return 0;
}

