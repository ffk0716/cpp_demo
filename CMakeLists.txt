cmake_minimum_required(VERSION 3.11)

project(demo)
enable_testing()
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(third_party)

# gtest
ExternalProject_Get_Property(google_test INSTALL_DIR)
include_directories(${INSTALL_DIR}/include)
link_directories(${INSTALL_DIR}/lib)
function(add_gtest name)
    add_dependencies(${name} third_party)
    target_link_libraries(${name} gtest_main gtest pthread)
    add_test(test_${name} ${name})
endfunction()


add_subdirectory(gtest)
add_subdirectory(nan)
add_subdirectory(smart_ptr)
