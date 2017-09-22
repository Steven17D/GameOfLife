#include "GameOfLife.h"
#include "Common.hpp"

// TODO migrate all game logic to GameOfLife class

int main() {
    unsigned short width, height;
    GetDesktopResolution(width, height);

    GameOfLife gameOfLife(width, height);
    gameOfLife.start();

    return 0;
}