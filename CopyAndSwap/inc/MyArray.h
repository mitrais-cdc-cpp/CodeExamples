/*
 * MyArray.h
 *
 *  Created on: Jul 26, 2016
 *      Author: developer
 */

#ifndef MYARRAY_H_
#define MYARRAY_H_

#include <algorithm> // std::copy
#include <cstddef> // std::size_t

/* 
 * example: Implementation old fashion unsafe copy constructor, 
 *
 */

class MyArray
{
public:
    // (default) constructor
	MyArray(std::size_t size = 0)
        : mSize(size),
          mArray(mSize ? new int[mSize]() : 0)
    {
    }

    // copy-constructor
	MyArray(const MyArray& other)
        : mSize(other.mSize),
          mArray(mSize ? new int[mSize] : 0)
    {
        std::copy(other.mArray, other.mArray + mSize, mArray);
    }

    // destructor
    ~MyArray()
    {
        delete[] mArray;
    }

    /*
     * assigned operator below show how normaly we do copy an object
     * 1. self assignment test
     * 2. Allocate a memory
     * 3. Copy over value
     * 4. Free old memory
     * 5. Refer to new memory
     */
    MyArray& operator=(const MyArray& other)
    {
        if (this != &other)   //(1)                                
        {
        	int* newArray ;
        	try {
                  // get the new data ready before we replace the old
                  std::size_t newSize = other.mSize;
                  newArray = newSize ? new int[newSize]() : 0;                //(2)
                  std::copy(other.mArray, other.mArray + newSize, newArray);  //(3)
        	}
        	catch(std::exception *ex)
        	{
        		delete [] newArray;
        		throw;

        	}

            // replace the old data (all are non-throwing)
            delete [] mArray;                                         //(4)
            mSize = newSize;                                          //(5)
            mArray = newArray;                                        //(5)
        }

        return *this;
    }

private:
    std::size_t mSize;
    int* mArray;
};



#endif /* MYARRAY_H_ */

