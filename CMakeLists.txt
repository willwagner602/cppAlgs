cmake_minimum_required(VERSION 3.6)
project(cppAlgs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp
        searchAlgorithms.cpp
        sortAlgorithms.cpp
        maxSubarray.cpp
        miscAlgorithms.cpp
        miscAlgorithms.hpp
        matrix.cpp
        matrix.hpp
        heap.hpp)
add_executable(cppAlgs ${SOURCE_FILES})