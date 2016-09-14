cmake_minimum_required(VERSION 3.1.0 FATAL_ERROR)
project(UrdlTest VERSION 0.1 LANGUAGES CXX)

set(_ECLIPSE_VERSION "4.5")

###############################################################################
## target definitions #########################################################
###############################################################################

#Generate the shared library from the sources
add_executable(UrdlTest main.cpp)

#Set Debug or Release
set(CMAKE_BUILD_TYPE Debug)

# no SSL support for urdl since we missing the Libs/Header
add_definitions(-DURDL_DISABLE_SSL=1)


###############################################################################
## compiler definitions########################################################
###############################################################################

#enable c++11 and set it required
#set_property(TARGET UrdlTest PROPERTY CXX_STANDARD 11)
#set_property(TARGET UrdlTest PROPERTY CXX_STANDARD_REQUIRED ON)

###############################################################################
## dependencies ###############################################################
###############################################################################

# BOOST
set(Boost_USE_STATIC_LIBS OFF) 
set(Boost_USE_MULTITHREADED ON)  
set(Boost_USE_STATIC_RUNTIME OFF) 
find_package(Boost 1.61 EXACT COMPONENTS system regex date_time REQUIRED)

# THREADS
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)


set(URDL_LIBRARY_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/urdl/lib)
set(URDL_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/env/urdl/inc)

find_library(
    URDL_LIBRARIES
    NAMES urdl
    PATHS ${CMAKE_CURRENT_LIST_DIR}/env/urdl
    PATH_SUFFIXES "lib"
    NO_DEFAULT_PATH
)


include_directories(${Boost_INCLUDE_DIRS} ${URDL_INCLUDE_DIRS})
link_directories(${Boost_LIBRARIES} ${URDL_LIBRARY_DIRS})
target_link_libraries(UrdlTest ${Boost_LIBRARIES} Threads::Threads ${URDL_LIBRARIES} -lssl -lcrypto)
