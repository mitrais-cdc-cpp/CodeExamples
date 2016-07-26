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

### Sources:
* https://en.wikipedia.org/wiki/Opaque_pointer