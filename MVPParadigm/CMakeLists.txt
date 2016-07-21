cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(mvp VERSION 0.1 LANGUAGES CXX)

###############################################################################
## target definitions #########################################################
###############################################################################

if(WIN32)
	message(STATUS "#######################")
	message(STATUS "# System OS = WINDOWS #")
	message(STATUS "#######################")
endif(WIN32)

if(UNIX) 
	message(STATUS "####################")
	message(STATUS "# System OS = UNIX #")
	message(STATUS "####################")
endif(UNIX)

###############################################################################
## target definitions #########################################################
###############################################################################

file(GLOB SOURCES
 main.cpp
 presenter/ApplicationPresenter.cpp
 model/ApplicationModel.cpp
 view/ApplicationView.cpp
 presenter/Presenter.cpp)
 
 message("Following sources found:")
foreach(a ${SOURCES})
  message("${a}")
endforeach()

#Generate the shared library from the sources
add_executable(mvp ${SOURCES})

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# just for example add some compiler flags
#target_compile_options(SpiderBite PUBLIC -Wextra)

###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
set_property(TARGET mvp PROPERTY CXX_STANDARD 11)
set_property(TARGET mvp PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################

# GTK+
find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)
add_definitions(${GTK3_CFLAGS_OTHER})

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})
target_link_libraries(mvp ${GTK3_LIBRARIES} )






