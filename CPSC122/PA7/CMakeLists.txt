# note: following this post for setting up CMake
# https://cliutils.gitlab.io/modern-cmake/chapters/basics/structure.html

cmake_minimum_required (VERSION 2.8)

project(PA7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wall")

# make an automatic library
add_library(pa_library ${PROJECT_NAME}.cpp ${PROJECT_NAME}.h LinkedList.cpp LinkedList.h Stack.cpp Stack.h Calculator.cpp Calculator.h)

# create unit test executable
add_subdirectory(test)

# create main executable
add_executable(run${PROJECT_NAME} Main.cpp ${PROJECT_NAME}.cpp LinkedList.cpp Stack.cpp Calculator.cpp)

