cmake_minimum_required(VERSION 3.15)
project(SantaFe)

set(CMAKE_CXX_STANDARD 14)

add_executable(SantaFe main.cpp Ant.cpp Ant.h AbstractNode.cpp AbstractNode.h IfFoodAheadNode.cpp IfFoodAheadNode.h MoveNode.cpp MoveNode.h Prog2Node.cpp Prog2Node.h Prog3Node.cpp Prog3Node.h TurnLeftNode.cpp TurnLeftNode.h TurnRightNode.cpp TurnRightNode.h TreeConstructor.cpp TreeConstructor.h)