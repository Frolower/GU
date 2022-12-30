cmake_minimum_required(VERSION 3.23)
project(PA9)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(PA9
        functions.cpp
        header.h
        main.cpp)
