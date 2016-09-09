#include <iostream>
using namespace std;
 
class Base
{
public:
    virtual void foo() = 0;
    virtual void bar() = 0;
};
 
class Derr1: virtual public Base
{
public:
    void foo()
    {
        std::cout << "Inside foo() of Derr1" << std::endl;
        bar();
    }
};
 
class Derr2: virtual public Base
{
public:
    void bar()
    {
        std::cout << "Inside bar() of Derr2" << std::endl;
    }
};
 
class Join: public Derr1, public Derr2
{
};
 
int main() {
    Join* test = new Join();
    test->foo();
    return 0;
}