1. Background
--------------

The copy and swap idiom is a way of implementing destructor, copy constructor and assignment operator of C++ class that manages a resource.
The implementation of copy and swap similiar to the rule of five.

In traditional way, assignment operator (operator=() ) usually do something like this
1. allocate memory 
2. copy parameter to new memory
3. release old memory
4. refer to the new copy

additionally, it need to check whether it try to assign given instance to the same instance. In most case it will assign an instance to difference instance.
But this approach completely exception unsave, especially with memory allocation.

2. What is Copy and Swap pattern
--------------------------------
The copy & swap pattern goal is not to handle the exception, instead it is try to guarantee the state of class after the exception has been thrown.
It allows us to effectively reduce the complexity of implementing the assignment operator and remove check instance process.

The swap method will do
1. copy by virtue of argument being passed by value
2. if copying fails, the function is not run at all, so the class unchange by the assignment because it truly didnt happen.
3. swapping the value parameter.


Resources
-------------
1. https://chara.cs.illinois.edu/sites/cgeigle/blog/2014/08/27/copy-and-swap/
2. http://www.cppsamples.com/common-tasks/copy-and-swap.html
3. https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Copy-and-swap
