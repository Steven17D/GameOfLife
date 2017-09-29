//
// Created by Steven on 9/22/2017.
//

#ifndef GAMEOFLIFE_GAMEOFLIFE_H
#define GAMEOFLIFE_GAMEOFLIFE_H

#include <sstream>
#include <map>
#include "GameController.h"
#include "Stopwatch.h"
#include "GameBoard.h"
#include "Patterns.h"

class GameOfLife {
public:
    GameOfLife(unsigned short screenWidth, unsigned short screenHeight, unsigned short cellSize = 20, unsigned short fps = 24);
    ~GameOfLife();

    void start();

private:
    void drawControllers(cimg_library::CImg<unsigned char> &image, Point drawLocation,
                         std::map<std::string, std::string> controllers, unsigned short fontSize = 26,
                         unsigned short textPaddingSize = 4);
    void showInfo(const GameBoard &gameBoard, cimg_library::CImg<unsigned char> &image);
    void calculateFrameRate();

    Stopwatch stopwatch;
    cimg_library::CImgDisplay imgDisplay;
    unsigned short wCount, hCount;
    GameBoard gameBoard;
    unsigned short fps;
    double realFps;
    bool showCenter;
};


#endif //GAMEOFLIFE_GAMEOFLIFE_H
