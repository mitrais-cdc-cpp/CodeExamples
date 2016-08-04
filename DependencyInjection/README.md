# Dependency Injection in C++
### Implementation of Dependency Injection in C++. This project created for C++ Bootcamp Training in Mitrais.

### Depenceny Injection:
Dependency injection is a technique used in object-oriented programming languages. It promotes loose coupling of components by passing dependencies to an object, rather than having an object instantiate its own dependencies.

Object-oriented design can lead to the creation of structures containing components that are dependent upon other classes, known as dependencies. In such situations, you may decide to instantiate a class's dependencies from within the dependent class, using the new keyword.

Dependency injection reduces the problem of tight coupling by removing the instantiation of dependencies from a dependent class. Instead, pre-constructed objects are passed to a dependent object at some time before they are required.

Types of Dependency Injection:
* Constructor Injection: the dependencies are provided through a class constructor.
* Setter Injection: the client exposes a setter method that the injector uses to inject the dependency.
* Interface Injection: the dependency provides an injector method that will inject the dependency into any client passed to it. Clients must implement an interface that exposes a setter method that accepts the dependency.

### Sources:
* http://bajamircea.github.io/coding/cpp/2015/11/01/dependency-injection-templates.html
* https://www.youtube.com/watch?v=IKD2-MAkXyQ
* http://www.blackwasp.co.uk/DependencyInjection.aspx
* http://programmaticallyspeaking.blogspot.co.id/2010/04/beautiful-dependency-injection-in-c.html

