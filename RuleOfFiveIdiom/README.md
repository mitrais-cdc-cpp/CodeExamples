# Rule of Five
### Implementation of Rule of Five Pattern in C++. This project created for C++ Bootcamp Training in Mitrais.

### Rule of Five:
The rule of five is a modern expansion of the rule of three. Firstly, the rule of three specifies that if a class implements any of the following functions, it should implement all of them:

* copy constructor
* copy assignment operator
* destructor

These functions are usually required only when a class is manually managing a dynamically allocated resource, and so all of them must be implemented to manage the resource safely.

In addition, the rule of five identifies that it usually appropriate to also provide the following functions to allow for optimized copies from temporary objects:

* move constructor
* move assignment operator


### Sources:
* https://en.wikipedia.org/wiki/Rule_of_three_(C%2B%2B_programming)
* http://www.cppsamples.com/common-tasks/rule-of-five.html
* https://www.youtube.com/watch?v=JsaTQiYDBb0
