cmake_minimum_required(VERSION 3.11)

project(demo)

set (CMAKE_CXX_STANDARD 11)
add_executable(hello main.cxx)

add_subdirectory(nan)
add_subdirectory(smart_ptr)
