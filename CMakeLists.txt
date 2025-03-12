cmake_minimum_required(VERSION 3.8)

project(Space_Impact_CMake)

set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(game)

add_executable(Space_Impact_CMake main.cpp)

target_link_libraries(Space_Impact_CMake game)
