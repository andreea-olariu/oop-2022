cmake_minimum_required(VERSION 3.20)
project(seminar_6_tema)

set(CMAKE_CXX_STANDARD 14)

add_executable(seminar_6_tema main.cpp Circuit.cpp Cars/Toyota.cpp Cars/Dacia.cpp Cars/Mercedes.cpp Cars/Ford.cpp Cars/Mazda.cpp)
