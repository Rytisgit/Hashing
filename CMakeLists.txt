cmake_minimum_required(VERSION 3.10)
project(hashing)
set(GCC_COVERAGE_COMPILE_FLAGS "-O3")
add_definitions(${GCC_COVERAGE_COMPILE_FLAGS})
set(CMAKE_CXX_STANDARD 17)

add_executable(hashing main.cpp RytisMasterClassOnHashingAlgorithms.h timer.h)