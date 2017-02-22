cmake_minimum_required(VERSION 3.6)
project(cppAlgs)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(SOURCE_FILES
        test-main.cpp
        test-algs.cpp
        Utilities.cpp
        SearchAlgorithms.cpp
        SortAlgorithms.cpp
        maxSubarray.cpp
        miscAlgorithms.cpp
        miscAlgorithms.hpp
        matrix.cpp
        matrix.hpp
        heap.hpp)
add_executable(cppAlgs ${SOURCE_FILES})