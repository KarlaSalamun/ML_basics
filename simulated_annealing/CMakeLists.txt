cmake_minimum_required(VERSION 3.15)
project(simulated_annealing)

set(CMAKE_CXX_STANDARD 14)

add_executable(simulated_annealing main.cpp ../test_functions/RastriginFunction.h ../test_functions/HimmelblauFunction.h
        ../test_functions/HimmelblauFunction.cpp ../test_functions/RastriginFunction.cpp
        ../test_functions/EasomFunction.cpp ../test_functions/EasomFunction.h ../test_functions/EggholderFunction.cpp
        ../test_functions/EggholderFunction.h ../test_functions/RosenbrockFunction.cpp
        ../test_functions/RosenbrockFunction.h SimulatedAnnealing.cpp SimulatedAnnealing.h CoolingScheme.h
        GeometricScheme.cpp GeometricScheme.h LinearScheme.cpp LinearScheme.h TF_optimization.cpp TF_optimization.h)