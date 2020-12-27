cmake_minimum_required(VERSION 3.17)
project(StringSearchComparison)

set(CMAKE_CXX_STANDARD 20)

add_executable(StringSearchComparison main.cpp BM/BoyerMoore.cpp BM/BoyerMoore.h KMP/KnuthMorrisPratt.cpp KMP/KnuthMorrisPratt.h RK/RabinKarp.cpp RK/RabinKarp.h)