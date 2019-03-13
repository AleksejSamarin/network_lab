cmake_minimum_required(VERSION 3.10)
project(network_lab)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(network_lab main.cpp)