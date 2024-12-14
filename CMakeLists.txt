cmake_minimum_required(VERSION 3.30)
project(AP5)

set(CMAKE_CXX_STANDARD 20)

add_executable(AP5 main.cpp
        array.h
        vector.h
        list.h
        array.cpp
        vector.cpp
        list.cpp)
