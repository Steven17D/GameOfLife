cmake_minimum_required(VERSION 3.7)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g -pthread")
#set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")

set(SOURCE_FILES src/main.cpp
        src/CImg.h
        src/mingw.thread.h src/mingw.mutex.h
        src/GameBoard.h src/GameBoard.cpp
        src/Point.h src/Point.cpp
        src/Shape.h
        src/Circle.h src/Circle.cpp
        src/Polygon.h src/Polygon.cpp
        src/Quadrangle.h src/Quadrangle.cpp
        src/Patterns.h)

add_executable(GameOfLife ${SOURCE_FILES})