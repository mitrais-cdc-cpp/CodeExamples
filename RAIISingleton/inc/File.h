#ifndef _RAAISINGLETON_OPENFILE_H_
#define _RAAISINGLETON_OPENFILE_H_

#include <mutex>
#include <iostream>
#include <string>
#include <fstream>
#include <stdexcept>

class File
{
 public:
     static File* getInstance();
     void write(const std::string& message);
     ~File();

 private:
     static File * instance;
     File();
     File(File const&);
     void operator=(File const&);
 };

#endif // _RAAISINGLETON_OPENFILE_H_
