cmake_minimum_required(VERSION 3.15)
project(simulated_annealing)

set(CMAKE_CXX_STANDARD 14)

add_executable(simulated_annealing main.cpp RastriginFunction.cpp RastriginFunction.h HimmelblauFunction.cpp
        HimmelblauFunction.h EasomFunction.cpp EasomFunction.h EggholderFunction.cpp EggholderFunction.h
        RosenbrockFunction.cpp RosenbrockFunction.h SimulatedAnnealing.cpp SimulatedAnnealing.h CoolingScheme.h
        GeometricScheme.cpp GeometricScheme.h LinearScheme.cpp LinearScheme.h ../function.cpp ../function.h )