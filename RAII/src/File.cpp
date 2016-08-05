#include "../inc/File.h"

File::File(const char* filename):m_file_handle(std::fopen(filename, "w+"))
{
	if(m_file_handle == NULL)
	{
		throw open_error() ;
	}
}
   
File::~File()
{
	std::fclose(m_file_handle) ;
}
 
void File::write(const char* str)
{
	if(std::fputs(str, m_file_handle) == EOF)
	{
		throw write_error() ;
	}
}
  
void File::write(const char* buffer, std::size_t num_chars)
{
	if(num_chars != 0 && std::fwrite(buffer, num_chars, 1, m_file_handle) == 0)
	{
		throw write_error() ;
	}
}
