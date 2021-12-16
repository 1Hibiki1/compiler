cmake_minimum_required(VERSION 3.16.3)
project("compiler")

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR} "src/*.c")
file(GLOB_RECURSE SOURCES_UTIL RELATIVE ${CMAKE_SOURCE_DIR} "src/util/*.c")
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

add_executable(tests tests/testall.c)
add_executable(uwu ${SOURCES})

