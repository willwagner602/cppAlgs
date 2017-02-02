cmake_minimum_required(VERSION 3.6)
project(cppAlgs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp searchAlgs.cpp sortAlgs.cpp)
add_executable(cppAlgs ${SOURCE_FILES})