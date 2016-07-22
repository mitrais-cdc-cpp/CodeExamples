//============================================================================
// Name        : main.cpp
// Author      : Ari Suarkadipa
// Version     :
// Copyright   : (c)2014 Satish Singhal
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>

using namespace std;
/**
 * Class of Integer, used for demo rule of five
 *
 * note
 *
 */
class Integer
{
private:
	int * data = nullptr;
public:
	/**
	 * Default constructor
	 */
	Integer(): data(new int(0))
	{
		cout << "From default CTOR\n";
	}

	/**
	 * Explicit constructor
	 *
	 * @param val
	 */
	explicit Integer(int val): data(new int(val))
	{
		cout << "From explicit CTOR\n";
	}

	/**
	 * Copy constructor
	 *
	 * @param other
	 */
	Integer(const Integer & other):data(new int(*other.data))
	{
		cout << "From copy CTOR\n";
	}

	/**
	 * Assignment operator
	 * later we should use copy and swap to get the value of pointer related this assignment operator
	 *
	 * @param other
	 * @return const Integer
	 */
	const Integer operator = (const Integer & other)
	{
		if (this != &other)
		{
			delete data;
			data = new int(*other.data);
		}
		cout << "From regular assignment operator.\n";
		return *this;
	}

	/**
	 * destructor
	 *
	 * all destructor should use virtual
	 */
	virtual ~Integer()
	{
		delete data;
		cout << "From destructor.\n";
	}

	/**
	 * Move copy constructor
	 *
	 * @param other
	 */
	Integer(Integer && other) //&& is called r value reference. All literals are r value references.
	{
		data = other.data; // data will just point to where other.data is pointing
		other.data = nullptr;
		cout << "From move CTOR\n";
	}

	/**
	 * Move assignment operator
	 * * later we should use copy and swap to get the value of pointer related this assignment operator
	 *
	 * @param other
	 * @return const Integer
	 */
	const Integer & operator = (Integer && other)
	{
		if (this != &other)
		{
			delete data;
			data = other.data;
			other.data = nullptr;
		}
		cout << "From move assignment operator.\n";
		return *this;
	}


	/**
	 * toString function
	 *
	 * @return const string
	 */
	const string toString() const
	{
		return (to_string(*data)+'\n');
	}
};

/**
 * printInteger function
 *
 * @param value
 */
void printInteger(Integer value)
{
	cout << value.toString();
}

/**
 * getInteger function
 *
 * @return Integer
 */
Integer getInteger()
{
	cout << "Enter int value: ";
	int val = 0;
	cin >> val;
	Integer X(val);
//	return X;
	return std::move(X);
}

int main() {
	// call explicit constructor
	Integer value5(5);
	cout << "Printing Integer value5.\n";

	// call copy constructor
 	printInteger(value5);

 	// call move copy constructor
	printInteger(std::move(value5));

	// call regular assignment operator
	Integer valueUser = getInteger();
	cout << "Printing Integer valueUser.\n";
	cout << valueUser.toString();

	// call explicit constructor
	Integer value10(10);

	// call default constructor
	Integer copyValue10;

	// call regular assignment operator
	copyValue10 = value10;
	cout << "Printing copyValue10.\n";

	// call explicit constructor
	Integer value9(9);

	// call default constructor
	Integer copyValue9;

	// call move assignment operator
	copyValue9 = std::move(value9);

	return 0;
}
