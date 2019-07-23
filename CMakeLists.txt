cmake_minimum_required(VERSION 3.11)

project(demo)
enable_testing()
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 11)

add_subdirectory(third_party)

# gtest
ExternalProject_Get_Property(google_test INSTALL_DIR)
include_directories(SYSTEM ${INSTALL_DIR}/include)
link_directories(${INSTALL_DIR}/lib)
function(add_gtest name)
    add_dependencies(${name} third_party)
    target_link_libraries(${name} gtest_main gtest pthread)
    add_test(test_${name} ${name})
endfunction()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

include_directories(common)

add_subdirectory(gtest_demo)
add_subdirectory(has_member)
add_subdirectory(hello)
add_subdirectory(nan)
add_subdirectory(size)
add_subdirectory(smart_ptr)
