
add_subdirectory(foo)

add_executable(cmake_link main.cxx)

target_link_libraries(cmake_link foo)
