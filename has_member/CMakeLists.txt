
get_filename_component(bin_name ${CMAKE_CURRENT_SOURCE_DIR} NAME)
add_executable(${bin_name} main.cxx)
add_gtest(${bin_name})
