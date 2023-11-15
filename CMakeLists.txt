cmake_minimum_required(VERSION 3.8)

project(Space_Impact_CMake)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(game)

add_executable(Space_Impact_CMake main.cpp)
