# Non Virtual Interface Pattern
### Implementation of Non Virtual Interface Pattern in C++. This project created for C++ Bootcamp Training in Mitrais.

### Non Virtual Interface Pattern:
The non-virtual interface pattern is a design pattern that controls how methods in a base class are overridden. Base classes include public, non-virtual members that may be called by clients and a set of overridable methods containing core functionality.

The non-virtual interface pattern separates the core functionality of a base class from its public interface. The public methods of the base class are neither virtual nor abstract so cannot be overridden. The public methods call private/protected virtual members in the base class, which contain core functionality that may be overridden in the derived.

The essence of the non-virtual interface pattern is that you have private virtual functions, which are called by public non-virtual functions (the non-virtual interface).

The advantage of this is that the base class has more control over its behaviour than it would if derived classes were able to override any part of its interface. In other words, the base class (the interface) can provide more guarantees about the functionality it provides.


### Sources:
* https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-Virtual_Interface
* http://www.blackwasp.co.uk/nvi.aspx
* http://stackoverflow.com/questions/6481260/non-virtual-interface-design-pattern-in-c-c
