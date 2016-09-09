# Delegate to a sister class
A powerful technique that arises from using virtual inheritance is to delegate a method from a class in another class by using a common abstract base class. This is also called cross delegation. Let's assume we have a similar scenario like in the diamond example, with small changes. 

Diamond Problem.

Implementaion:

```C++
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
```

The result : 

```C++
Inside foo() of Derr1
Inside bar() of Derr2
```
Believe it or not, when Derr1::foo() calls this->bar(), it ends up calling Derr2::bar(). Yes, that’s right: a class that Derr1 knows nothing about will supply the override of a virtual function invoked by Derr1::foo(). This “cross delegation” can be a powerful technique for customizing the behavior of polymorphic classes.