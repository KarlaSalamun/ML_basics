cmake_minimum_required(VERSION 3.10)
project(SantaFe)

set(CMAKE_CXX_COMPILER "g++")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -std=c++11 -Wall")
find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})
add_executable(SantaFe main.cpp Ant.cpp Ant.h AbstractNode.cpp AbstractNode.h IfFoodAheadNode.cpp IfFoodAheadNode.h MoveNode.cpp MoveNode.h Prog2Node.cpp Prog2Node.h Prog3Node.cpp Prog3Node.h TurnLeftNode.cpp TurnLeftNode.h TurnRightNode.cpp TurnRightNode.h TreeConstructor.cpp TreeConstructor.h ../Solution.h ../Solution.cpp ../GeneticAlgorithm.cpp ../GeneticAlgorithm.h TreePopulation.cpp TreePopulation.h TreeFunction.cpp TreeFunction.h
        TreeCrossover.cpp TreeCrossover.h ../SelectionOperator.cpp ../SelectionOperator.h ../MutationOperator.cpp ../MutationOperator.h
        ../CrossoverOperator.cpp ../CrossoverOperator.h TreeSelection.cpp TreeSelection.h TreeMutation.cpp TreeMutation.h
        DrawTrail.cpp DrawTrail.h)
target_link_libraries(SantaFe ${CURSES_LIBRARIES})
