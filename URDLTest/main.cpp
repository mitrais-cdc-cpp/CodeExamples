//
// get2.cpp
// ~~~~~~~~
//
// Copyright (c) 2009 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <urdl/read_stream.hpp>
#include <urdl/istream.hpp>
#include <boost/progress.hpp>
#include <iostream>
#include <fstream>

int main(int argc, char* argv[])
{
  try
  {
    if (argc != 3)
    {
      std::cerr << "Usage: get2 <url> <outputfile>\n";
      return 1;
    }
/*

    urdl::option_set options;
    //options.set_option(urdl::http::max_redirects(2));
    urdl::istream is("http://www.boost.org");
    if(is.is_open())
    	std::cout << "success";
    //urdl::istream is(argv[1]);
	if (!is)
	{
	  std::cout << is.error().message() << std::endl;
	}


	std::ofstream os(argv[2], std::ios_base::out | std::ios_base::binary);
	if (is.content_length() != std::numeric_limits<std::size_t>::max())
	{
	  boost::progress_display progress(is.content_length());
	  while (is && os)
	  {
		char buffer[1024] = "";
		is.read(buffer, sizeof(buffer));
		os.write(buffer, is.gcount());
		progress += is.gcount();
	  }
	  std::cout << std::endl;
	}
	else
	{
	  os << is.rdbuf();
	}



*/

    std::ofstream os(argv[2], std::ios_base::out | std::ios_base::binary);
    boost::asio::io_service io_service;
    urdl::read_stream stream(io_service);
    stream.open("http://www.google.de");

    for (;;)
    {
      char data[1024];
      boost::system::error_code ec;
      std::size_t length = stream.read_some(boost::asio::buffer(data), ec);
      if (ec == boost::asio::error::eof)
        break;
      if (ec)
        throw boost::system::system_error(ec);
      os.write(data, length);
    }
  }
  catch (std::exception& e)
  {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
}
