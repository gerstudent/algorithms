cmake_minimum_required(VERSION 3.21)
project(AlgoRhythms)

set(CMAKE_CXX_STANDARD 20)

add_executable(greedy greedy_algorithm.cpp)
add_executable(euclidean euclidean_algo.cpp)
add_executable(ext_euclidean ext_euclidean_algo.cpp)

