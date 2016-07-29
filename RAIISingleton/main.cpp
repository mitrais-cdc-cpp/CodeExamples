#include "inc/File.h"

int main()
{
	File file("log.txt");
	file.write("test");

	std::cout << "Success";

	 // continue writing to logfile.txt ...

	 // logfile.txt will automatically be closed because logfile's
	 // destructor is always called when example_with_RAII() returns or
	 // throws an exception.

	return 0;
}
