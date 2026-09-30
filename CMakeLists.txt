cmake_minimum_required(VERSION 4.1)
project(PigDice_1_0)

set(CMAKE_CXX_STANDARD 20)

add_executable(PigDice_1_0 main.cpp
        Die.cpp
        Die.h)
