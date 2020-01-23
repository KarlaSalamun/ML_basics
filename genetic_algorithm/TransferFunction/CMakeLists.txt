cmake_minimum_required(VERSION 3.10)
project(TransferFunction)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
add_executable(TransferFunction main.cpp ../../function.h
        ../CrossoverOperator.h ../CrossoverOperator.cpp Crossover/SimpleCrossover.cpp Crossover/SimpleCrossover.h
        Crossover/ArithmeticCrossover.cpp Crossover/ArithmeticCrossover.h Crossover/BLX_alpha.cpp Crossover/BLX_alpha.h
        ../MutationOperator.cpp ../MutationOperator.h Mutation/UniformMutation.cpp Mutation/UniformMutation.h
        Mutation/NormalMutation.cpp Mutation/NormalMutation.h ../GeneticAlgorithm.cpp ../GeneticAlgorithm.h
        TF_optimization.h TF_optimization.cpp
        ../../Solution.cpp ../../Solution.h
        Selection/TournamentSelection.cpp Selection/TournamentSelection.h
        Selection/RouletteSelection.cpp Selection/RouletteSelection.h)
