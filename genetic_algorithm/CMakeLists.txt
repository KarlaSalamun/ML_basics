cmake_minimum_required(VERSION 3.10)
project(genetic_algorithm)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
add_executable(genetic_algorithm main.cpp ../function.h ../simulated_annealing/RastriginFunction.h ../simulated_annealing/RastriginFunction.cpp CrossoverOperator.cpp CrossoverOperator.h SimpleCrossover.cpp SimpleCrossover.h ArithmeticCrossover.cpp ArithmeticCrossover.h BLX_alpha.cpp BLX_alpha.h MutationOperator.cpp MutationOperator.h UniformMutation.cpp UniformMutation.h NormalMutation.cpp NormalMutation.h GeneticAlgorithm.cpp GeneticAlgorithm.h ../simulated_annealing/TF_optimization.h ../simulated_annealing/TF_optimization.cpp ../Solution.cpp ../Solution.h TournamentSelection.cpp TournamentSelection.h RouletteSelection.cpp RouletteSelection.h)
