
include_directories(${PROJECT_SOURCE_DIR}/src/common)
get_filename_component(bin_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_gtest_executable(${bin_name} main.cxx)
