
add_library(foo_a OBJECT foo_a.cxx)
target_include_directories(foo_a PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
add_foo_src(foo_a)
