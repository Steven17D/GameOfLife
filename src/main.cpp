#include "GameOfLife.h"
#include "Common.hpp"


int main() {
    unsigned short width, height;
    GetDesktopResolution(width, height);

    GameOfLife gameOfLife(width, height, 4);
    gameOfLife.start();

    return 0;
}