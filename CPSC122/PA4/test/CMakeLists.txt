# setup google test
add_subdirectory(lib/gtest-1.7.0)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# to be able to access the header file in parent directory
target_include_directories(pa_library PUBLIC ../)

# tests have their own executable
add_executable(runTests Test.cpp)

# linked to main library and google test
target_link_libraries(runTests pa_library gtest gtest_main)

