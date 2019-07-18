

add_custom_target(third_party)

include(ExternalProject)
set_directory_properties(PROPERTIES EP_BASE ${CMAKE_CURRENT_BINARY_DIR})
ExternalProject_Add(google_test
    GIT_REPOSITORY    https://github.com/google/googletest.git
    GIT_TAG           master
    UPDATE_COMMAND ""
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=<INSTALL_DIR>)

add_dependencies(third_party google_test)
