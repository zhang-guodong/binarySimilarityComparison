cmake_minimum_required(VERSION 3.9)
project(binarySimilarityComparison)

set(CMAKE_CXX_STANDARD 11)

add_executable(binarySimilarityComparison main.cpp mapOfMIPSInstructionSet.cpp mapOfMIPSInstructionSet.h RabinKarpAlgorithm.cpp RabinKarpAlgorithm.h)