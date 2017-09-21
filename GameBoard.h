//
// Created by Steven on 9/20/2017.
//

#ifndef GAMEOFLIFE_GAMEBOARD_H
#define GAMEOFLIFE_GAMEBOARD_H

#include <iostream>
#include <vector>
#include "CImg.h"
#include "Point.h"

#define LIVE true
#define DEAD false

typedef std::vector<std::vector<bool>> Grid;

class GameBoard {
public:
    GameBoard(unsigned short width, unsigned short height);
    ~GameBoard();

    void draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]);
    void next();
    void clear();

    std::vector<bool>* operator[](unsigned int index);
    bool operator()(unsigned int x, unsigned int y);
    void operator()(unsigned int x, unsigned int y, bool value);

    void initFull();
    void initRandom();

private:
    Grid board;
    unsigned short width;
    unsigned short height;

    int countLiveNeighbors(unsigned int x, unsigned int y);
    bool is_onBoard(unsigned int x, unsigned int y);
    void insertPattern(Point location, Grid pattern);
};


#endif //GAMEOFLIFE_GAMEBOARD_H
