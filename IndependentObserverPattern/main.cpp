#include <iostream>
#include <functional>
#include "subject/Subject.h"

struct A
{
	void foo()
	{
		std::cout << "foo()\n";
	}
};

struct B
{
	static void bar()
	{
		std::cout << "bar()\n";
	}
};

int main(int argc, char* argv[])
{
	Subject s;

	A a;
	B b;

	s.registerObserver(Event::RED, &B::bar);
	s.registerObserver(Event::BLUE, std::bind(&A::foo, &a));
	s.registerObserver(Event::MAGENTA, std::bind(&A::foo, &a));

	s.notify(Event::RED);
	s.notify(Event::BLUE);
	s.notify(Event::MAGENTA);


	return 0;
}
