#include <iostream>
#include "inc/Timespan.h"

using namespace std;


std::ostream& operator<<(std::ostream& os, const Timespan& ts)
{
	/* Dont need to be changed, we using the public interface! */
	os << ts.hours() << ":" << ts.minutes() << ":" << ts.seconds();
}

void print(Timespan ts_)
{
	std::cout << ts_ << std::endl; 
}

int main()
{
	// our class allocates 3 integer (12Bytes) on the stack, compiler have to know that.
	// if we change the size of Timespan, this have to be recompiled because stack allocation is different
	std::cout << sizeof(Timespan) << std::endl; 

	Timespan t(3600);
	print(t);

	Timespan s(64);
	t = s;
	print(t);
	print(s);

	return 0;
}
