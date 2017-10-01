cmake_minimum_required(VERSION 3.7)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++")

if( CMAKE_BUILD_TYPE EQUAL "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

set(SOURCE_FILES
        src/CImg.h
        src/Shape.h
        src/main.cpp          src/Common.hpp
        src/mingw.thread.h    src/mingw.mutex.h
        src/GameBoard.h       src/GameBoard.cpp
        src/Point.h           src/Point.cpp
        src/Circle.h          src/Circle.cpp
        src/Polygon.h         src/Polygon.cpp
        src/Quadrangle.h      src/Quadrangle.cpp
        src/Patterns.h        src/Patterns.cpp
        src/Stopwatch.h       src/Stopwatch.cpp
        src/GameOfLife.h      src/GameOfLife.cpp
        src/GameController.h  src/GameController.cpp)

add_executable(GameOfLife ${SOURCE_FILES})