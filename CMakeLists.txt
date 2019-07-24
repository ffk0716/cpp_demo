cmake_minimum_required(VERSION 3.11)

project(demo)
enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(third_party)
add_subdirectory(src)
