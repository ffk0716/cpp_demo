
add_library(foo foo.cxx)
target_include_directories(foo PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

function(add_foo_src n)
target_sources(foo PUBLIC $<TARGET_OBJECTS:${n}>)
target_include_directories(foo PUBLIC $<BUILD_INTERFACE:$<TARGET_PROPERTY:${n},INTERFACE_INCLUDE_DIRECTORIES>>)
endfunction()

add_subdirectory(foo_a)
