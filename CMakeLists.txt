cmake_minimum_required(VERSION 3.29)
project(OnTheWay)

set(CMAKE_CXX_STANDARD 20)

add_executable(OnTheWay main.cpp
        Package.h
        Package.cpp
        Graph.h
        Graph.cpp)
