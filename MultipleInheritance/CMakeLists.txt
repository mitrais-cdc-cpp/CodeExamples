cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)

set (OUTPUT_FILE_NAME MultipleInheritance)

project(${OUTPUT_FILE_NAME} VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "3.8")

###############################################################################
## file globbing ##############################################################
###############################################################################

file(GLOB SOURCES
 	inc/scenario1/*.hpp
 	inc/scenario2/*.hpp
 	inc/scenario3/*.hpp
 	inc/scenario3b/*.hpp

 	src/scenario1/*.cpp
 	src/scenario2/*.cpp
 	src/scenario3/*.cpp
 	src/scenario3b/*.cpp

	main.cpp
 )

message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(${OUTPUT_FILE_NAME} ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET ${OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD 11)
set_property(TARGET ${OUTPUT_FILE_NAME} PROPERTY CXX_STANDARD_REQUIRED ON)
