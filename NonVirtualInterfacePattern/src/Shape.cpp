#include "../inc/Shape.h"

namespace Mitrais
{
	/**
	 * Default constructor
	 */
	Shape::Shape()
	{
	}

	/**
	 * Default destructor
	 */
	Shape::~Shape()
	{
	}

	/**
	 * This function will print the area of particular shape.
	 * The non virtual function. This public method cannot be overridden in child class.
	 * The public methods call private virtual members in the base class,
	 * which contain core functionality that may be overridden in child class.
	 */
	void Shape::printArea()
	{
		// Call the virtual member
		cout << "The area of " << getType() << " is " << getArea() << endl;
	}

	/**
	 * The function to get the type of the shape.
	 * The base class will give the default value,
	 * but the child class can override this function
	 * @return The type of shape
	 */
	std::string Shape::getType()
	{
		return "Shape";
	}
}  // namespace Mitrais
