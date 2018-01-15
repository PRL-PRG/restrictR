cmake_minimum_required(VERSION 3.7)
project(restrictr)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g3 -ggdb -Wall")
set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES src/init.c src/restrictr.h src/restrictr.cpp)

include_directories(src ../R-dyntrace/include ../R-dyntrace/src/include)

add_library(restrictr ${SOURCE_FILES})
#add_executable(restrictr ${SOURCE_FILES})