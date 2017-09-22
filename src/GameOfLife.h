//
// Created by Steven on 9/22/2017.
//

#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H

#include <sstream>
#include "GameController.h"
#include "Stopwatch.h"
#include "GameBoard.h"
#include "Patterns.h"

class GameOfLife {
public:
    GameOfLife(unsigned short screenWidth, unsigned short screenHeight, unsigned short cellSize = 20, unsigned short fps = 24);

    void start();

private:
    void showInfo(GameBoard gameBoard, cimg_library::CImg<unsigned char> &image, unsigned short fps, Stopwatch stopwatch);

    Stopwatch stopwatch;
    cimg_library::CImgDisplay imgDisplay;
    unsigned short wCount, hCount;
    GameBoard gameBoard;
    unsigned short fps;
};


#endif //GAMEOFLIFE_GAMEOFLIFE_H
