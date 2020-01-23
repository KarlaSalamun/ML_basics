cmake_minimum_required(VERSION 3.15)
project(steepest_descent)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(steepest_descent
        CMakeLists.txt
        main.cpp
        main.h
        quadratic_function.cpp
        quadratic_function.h numeric_optimization.cpp numeric_optimization.h ../optimization_function.cpp
        ../optimization_function.h
        )
