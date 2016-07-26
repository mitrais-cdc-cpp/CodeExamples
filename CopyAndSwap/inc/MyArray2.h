/*
 * MyArray2.h
 *
 *  Created on: Jul 26, 2016
 *      Author: developer
 */

#ifndef MYARRAY2_H_
#define MYARRAY2_H_

#include <algorithm>
#include <cstddef>

using std::swap;

/*
 * Example implementation of copy constructor with copy and swap
 */
class MyArray2
{
public:
    // (default) constructor
	MyArray2(std::size_t size = 0)
        : mSize(size),
          mArray(mSize ? new int[mSize]() : 0)
    {
    }

    // copy-constructor
	MyArray2(const MyArray2& other)
        : mSize(other.mSize),
          mArray(mSize ? new int[mSize] : 0)
    {

    }

    // destructor
    ~MyArray2()
    {
        delete[] mArray;
    }

	// the operator assignment more simple and efficient.
	// The five steps (see at MyArray.h) has been handled by one line of code.
	MyArray2& operator=(const MyArray2& other)
	{
		swap(*this, other); // (2)

		return *this;
	}

	friend void swap(MyArray2& first, MyArray2& second) // nothrow
	{
		// by swapping the members of two classes,
		// the two classes are effectively swapped
		swap(first.mSize, second.mSize);
		swap(first.mArray, second.mArray);
	}

private:
    std::size_t mSize;
    int* mArray;
};



#endif /* MYARRAY2_H_ */

