cmake_minimum_required(VERSION 3.12)

project(learn_gtest C CXX)

set(lib_name functions_lib)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

add_subdirectory(functions_lib)

add_subdirectory(app)

enable_testing()

add_subdirectory(test)
