# PIMPL (Pointer to Implementation)
a.k.a. 
- Handle Body, 
- Cheshire Cat, 
- opaque pointer, 
- d-pointer, 
- Compiler-firewall idiom

### This project created for C++ Bootcamp Training in Mitrais.

### Why we using PIMPL:
The PIMPL Idiom is a technique for implementation hiding in which a public class wraps
a structure or class that cannot be seen outside the library the public class is part of.

Pointer to Implmentation are a way to hide the implementation details of an interface from ordinary clients,
so that the implementation may be changed without the need to recompile the modules using it. 
This benefits the programmer as well since a simple interface can be created, 
and most details can be hidden in another file.
This is important for providing binary code compatibility through different versions of a shared library, 
for example.

### Creating steps
- Create a forward declaration INSIDE the class within private access (e.g. struct Impl;)
- Declare a pointer to forward declared class (e.g. Impl* pimpl;)
- Remove all existing private member and function declarations
- Create a struct/class and insert all removed private member and functions
- Edit the existing implementation to direct read or write to the member through the "pimpl" (see: Timespan.cpp)
- Make sure to delete the pimpl pointer!
- Make sure that "Rule of 5 Idiom" is implemented
- Provide strong exception guarantee with "Copy & Swap Idiom"


### Sources:
* https://en.wikipedia.org/wiki/Opaque_pointer
* https://www.youtube.com/watch?v=jYThYohGMqw