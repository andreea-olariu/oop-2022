cmake_minimum_required(VERSION 3.20)
project(Simulare_Test)

set(CMAKE_CXX_STANDARD 14)

add_executable(Simulare_Test main.cpp EasyHash.cpp CountAsciiHash.cpp CountConsonantHash.cpp CountVowelsHash.cpp Hash.cpp HashManager.cpp)
