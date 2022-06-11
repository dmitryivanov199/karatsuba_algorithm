cmake_minimum_required(VERSION 3.21)
project(karatsuba_algorithm)

set(CMAKE_CXX_STANDARD 14)

add_executable(karatsuba_algorithm main.cpp src/number.h src/number.cpp src/karatsuba_algorithm.h src/karatsuba_algorithm.cpp)
