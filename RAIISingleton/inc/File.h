#ifndef _RAAISINGLETON_OPENFILE_H_
#define _RAAISINGLETON_OPENFILE_H_

#include <iostream>
#include <cstdio>

 // exceptions
 class file_error { } ;
 class open_error : public file_error { } ;
 class close_error : public file_error { } ;
 class write_error : public file_error { } ;

 class File
 {
 public:
     File( const char* filename );

     ~File();

     void write( const char* str);

     void write( const char* buffer, std::size_t num_chars );

 private:
     std::FILE* m_file_handle ;

     // copy and assignment not implemented; prevent their use by
     // declaring private.
     File( const File & ) ;
     File & operator=( const File & ) ;
 } ;


#endif // _RAAISINGLETON_OPENFILE_H_
