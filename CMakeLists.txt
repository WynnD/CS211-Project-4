cmake_minimum_required(VERSION 3.3)
project(project4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

set(SOURCE_FILES project4.h project4.c proj4base.c)
add_executable(project4 ${SOURCE_FILES})