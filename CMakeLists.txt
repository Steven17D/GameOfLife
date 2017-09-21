cmake_minimum_required(VERSION 3.7)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -pthread")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(SOURCE_FILES main.cpp
        CImg.h
        mingw.thread.h mingw.mutex.h
        GameBoard.h GameBoard.cpp
        Point.h Point.cpp
        Shape.h
        Circle.h Circle.cpp
        Polygon.h Polygon.cpp
        Quadrangle.h Quadrangle.cpp
        Patterns.h)

add_executable(GameOfLife ${SOURCE_FILES})