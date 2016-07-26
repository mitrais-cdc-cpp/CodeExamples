/*
 * main.cpp
 *
 *  Created on: Jul 22, 2016
 *      Author: developer
 */

#include <utility>

using std::swap;

class MyClass {
private:
	char *str;
	std::size_t size;

public:

	/*
	 * In traditional way, assignment operator (operator=() ) usually do something like this
	 * 1. allocate memory
	 * 2. copy parameter to new memory
	 * 3. release old memory
	 * 4. refer to the new copy
	 *
	 * The copy & swap pattern goal is not to handle the exception,
	 * instead it is try to guarantee the state of class after the exception has been thrown.
	 * It allows us to effectively reduce the complexity of implementing the assignment operator.
	 * For step above reduce, become 2
	 * 1. allocate memory
	 * 2. swaping the given parameter
	 */
	MyClass & operator=(const MyClass &s)
	{
		MyClass temp(s);          // Copy-constructor -- RAII
		temp.swap(*this);         // Non-throwing swap

		return *this;
	}                             // Old resources released when destructor of temp is called.

	/*
	 * Method to swap
	 */
	void swap(MyClass & s) throw()
	{
		std::swap(this->str, s.str);
	}
};

int main() {

	return 0;
}



