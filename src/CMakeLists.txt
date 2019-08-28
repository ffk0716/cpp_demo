
set(CMAKE_CXX_STANDARD 11)
# gtest

function(add_gtest_executable name)
    ExternalProject_Get_Property(google_test INSTALL_DIR)
    include_directories(SYSTEM ${INSTALL_DIR}/include)
    link_directories(${INSTALL_DIR}/lib)
    add_executable(${name} ${ARGN})
    add_dependencies(${name} google_test)
    target_link_libraries(${name} gtest_main gtest pthread)
    add_test(test_${name} ${name})
endfunction()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra")

add_subdirectory(cmake)
add_subdirectory(const)
add_subdirectory(gtest_demo)
add_subdirectory(has_member)
add_subdirectory(hello)
add_subdirectory(nan)
add_subdirectory(size)
add_subdirectory(smart_ptr)
