cmake_minimum_required(VERSION 2.8.12)

project(OdbSample)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/Modules")

find_package(ODB REQUIRED COMPONENTS mssql)
include(${ODB_USE_FILE})

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/inc/entity)

set(OdbSample_SOURCES
	main.cpp)

set(OdbSample_HEADERS
	inc/database.h)

set(OdbSample_ENTITY_HEADERS
	inc/entity/person.h)

set(OdbSample_ODB_SOURCES
	inc/odb_gen/person_odb.cpp)


odb_compile(OdbSample_SOURCES FILES ${OdbSample_ENTITY_HEADERS} DB mssql GENERATE_QUERY GENERATE_SESSION)

add_executable(OdbSample
	${OdbSample_SOURCES}
	${OdbSample_ODB_SOURCES})
target_link_libraries(OdbSample
	${ODB_LIBRARIES})
target_include_directories(OdbSample
	PRIVATE
		${OdbSample_HEADERS}
		${ODB_INCLUDE_DIRS}
		${OdbSample_ENTITY_HEADERS}
		${ODB_COMPILE_OUTPUT_DIR})
target_compile_definitions(OdbSample
	PRIVATE
		DATABASE_MSSQL)
