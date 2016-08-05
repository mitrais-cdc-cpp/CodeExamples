# Resource Acquisition is Initialisation (RAII)
a.k.a. 
- Execute-Around Object,
- Resource Release Is Finalization,
- Scope-Bound Resource Management (SBRM),
- Constructor Acquires,
- Destructor Releases (CADRe)

### This project created for C++ Bootcamp Training in Mitrais.

### Why we using RAII:
The **Resource Acquisition is Initialisation (RAII)** Idiom is a technique for exception-safe resource management. C++ basically forces you to use exceptions, because there is no other way to signal the failure of a constructor method. You either ensure that all constructors never fail, which makes the design of your classes awkward, or you throw exceptions on failure.

In **RAII**, holding a resource is a class invariant, and is tied to object lifetime: resource allocation (acquisition) is done during object creation (specifically initialization), by the constructor, while resource deallocation (release) is done during object destruction (specifically finalization), by the destructor. Thus the resource is guaranteed to be held between when initialization finishes and finalization starts (holding the resources is a class invariant), and to be held only when the object is alive. Thus if there are no object leaks, there are no resource leaks.

When we say 'Resource' we don't just mean memory - it could be file handles, network sockets, database handles, GDI objects and etc. In short, things that we have a finite supply of and so we need to be able to control their usage. The 'Scope-bound' aspect means that the lifetime of the object is bound to the scope of a variable, so when the variable goes out of scope then the destructor will release the resource. A very useful property of this is that it makes for greater exception-safety.

### Exception-safety and Common Pitfalls in C++
Given that the use of exceptions is inevitable, your code needs to be exception-safe. Here are some common, yet unsafe, scenarios:
```C++
File f;
f.open("boo.txt");
//UNSAFE - an exception here means the file is never closed
loadFromFile(f);
f.close();

Dog* dog = new Daschund;
//UNSAFE - an exception here means the dog is never deleted
goToThePark(dog); 
delete dog;

Lock* lock = getLock();
lock.aquire();
//UNSAFE - an exception here means the lock is never released
doSomething();
lock.release();
```
Not only will exceptions break your code, it's also easy to just forget to close a file. Maybe you close the file 99% of the time but there is one rare edge case that you forgot about. It would be nice if there was a safeguard for these situations — something that was guaranteed to close the file so we can't forget to do it.

### Solution 
When we aquire a resource (such as opening a file) what we want is to guarantee that we run code to relinquish that resource (such as closing the file). Luckily, there is a way to guarantee that code will run in C++. **C++ guarantees that the destructors of objects on the stack will be called, even if an exception is thrown.**

So we just need to get the file closing code into the destructor of some class, and then make an instance of that class on the stack.

```C++
class FileCloser {
public:
    FileCloser(File* file) {
        _file = file;
    }
    ~FileClose() {
        _file->close();
    }
private:
    File* _file;
}

// then we can use it like this
File f;
f.open("boo.txt");
FileCloser closer(&f);
//SAFE - Even if this throws an exception the FileCloser destructor will run and close the file.
loadFromFile(f);
//don't need to close the file here because the FileCloser destructor will run at this point
```

This is a very naive solution with a couple of problems. so don't use it, but it does give you an idea of what we are trying to achieve. 

One problem with this is that we might forget to make a `FileCloser`, in the same way that we might forget to close the file. It would be much better if the `File` class could just close itself. Let's make a new class called `MyFile` that closes itself:

```C++
class MyFile {
public:
    MyFile() {}
    
    ~MyFile() {
        if(_file.isOpen()){
            _file.close();
        }
    }
    
    void open(const char* filename) {
        _file.open(filename);
    }
    
    bool isOpen() const {
        return _file.isOpen();
    }
    
    void close() {
        if(_file.isOpen()){
            _file.close();
        }
    }
    
    std::string readLine() {
        return _file.readLine();
    }
    
private:
    File _file;
};


// then we can use it like this
MyFile f;
f.open("boo.txt");
//SAFE - The MyFile destructor is guaranteed to run
loadFromFile(f);
```

That is looking a lot better. Using `MyFile` is simpler and cleaner than `FileCloser`, and it's exception-safe as well. We can still do better, though. What if someone calls the `open` method twice? Also, it's annoying to check `isOpen` everywhere.

Let's take a different approach. What if we make a class that represents an open file? That way, we don't have to worry about opening twice, or closing twice, and we don't even have to check if the file is open.

```C++
class OpenFile {
public:
    OpenFile(const char* filename){
        //throws an exception on failure
        _file.open(filename);
    }
    
    ~OpenFile(){
        _file.close();
    }
    
    std::string readLine() {
        return _file.readLine();
    }
    
private:
    File _file;
};


// then we can use it like this
OpenFile f("boo.txt");
//exception safe, and no closing necessary
loadFromFile(f);
```

`OpenFile` is exception safe, and nice and simple. We have implemented across RAII. 

### Common Uses of RAII
When it comes to opening and closing files, `std::fstream` or `std::ofstream` already has an RAII type of design because it closes itself in its destructor.

The Boost library uses RAII for locking and unlocking with classes like `boost::lock_guard` and `boost::interprocess::scoped_lock`.

### RAII can use for
1. Reading file
2. Network sockets management
3. Database handles
4. DGI Objects
5. Every resource that need to ensure only live initizalisation finishes and finalization starts.

### Sources:
* https://en.wikipedia.org/wiki/Resource_Acquisition_Is_Initialization
* https://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Resource_Acquisition_Is_Initialization
* http://www.tomdalling.com/blog/software-design/resource-acquisition-is-initialisation-raii-explained/
* http://stackoverflow.com/questions/2321511/what-is-meant-by-resource-acquisition-is-initialization-raii
* https://en.wikibooks.org/wiki/C%2B%2B_Programming/RAII