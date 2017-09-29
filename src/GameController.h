//
// Created by Steven on 9/22/2017.
//

#ifndef GAMEOFLIFE_GAMECONTROLLER_H
#define GAMEOFLIFE_GAMECONTROLLER_H


#include "CImg.h"
#include "mingw.thread.h"
#include "mingw.mutex.h"
#include "Stopwatch.h"

class GameController {
public:
    GameController(cimg_library::CImgDisplay &imgDisplay,
                   Stopwatch &stopwatch,
                   bool &showCenter, unsigned short &fps);
    ~GameController();

    void start();

private:

    void KeyboardControl();

    cimg_library::CImgDisplay& imgDisplay;
    Stopwatch &stopwatch;
    bool &showCenter, threadAlive;
    unsigned short &fps;
};


#endif //GAMEOFLIFE_GAMECONTROLLER_H
