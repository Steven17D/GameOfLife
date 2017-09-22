//
// Created by Steven on 9/22/2017.
//

#include <map>
#include "GameOfLife.h"
#include "Common.hpp"

GameOfLife::GameOfLife(unsigned short screenWidth, unsigned short screenHeight, unsigned short cellSize, unsigned short fps)
        : imgDisplay(screenWidth, screenHeight, "Game Of Life", 3, true),
          wCount((const unsigned short) imgDisplay.width() / cellSize),
          hCount((const unsigned short) imgDisplay.height() / cellSize),
          gameBoard(wCount,hCount),
          fps(fps) { }

void GameOfLife::start() {
    // TODO add dialog for pattern choosing
    Point middleScreen(wCount / 2, hCount / 2);
    gameBoard.initPattern(Patterns::gosperGliderGun, middleScreen);

    bool threadAlive = true;
    bool showCenter  = false;

    GameController gameController(imgDisplay, stopwatch, showCenter, threadAlive, fps);
    gameController.start();
    stopwatch.start();

    do {
        cimg_library::CImg<unsigned char> image((const unsigned int) imgDisplay.width(), (const unsigned int) imgDisplay.height(), 1, 3, 1);
        gameBoard.draw(image, purple);
        showInfo(gameBoard, image, fps, stopwatch);
        if (showCenter) image.draw_circle(imgDisplay.width() / 2, imgDisplay.height() / 2, 1, red);

        if (!stopwatch.isStopped())
            gameBoard.next();
        
        imgDisplay.display(image);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    } while (!imgDisplay.is_closed());

    threadAlive = false;
}

void GameOfLife::showInfo(GameBoard gameBoard, cimg_library::CImg<unsigned char>& image, unsigned short fps, Stopwatch stopwatch) {
    Point drawLocation(10, 10);
    const unsigned short
            fontSize = 26,
            textPaddingSize = 4;

    std::chrono::high_resolution_clock::duration deltaTime = stopwatch.getDuration();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime).count() % 1000,
            seconds = std::chrono::duration_cast<std::chrono::seconds>(deltaTime).count() % 60,
            minutes = std::chrono::duration_cast<std::chrono::minutes>(deltaTime).count() % 60;

    std::ostringstream timeString;
    timeString << "Time: " <<
               fillString(std::to_string(minutes), 2, '0') << ":" <<
               fillString(std::to_string(seconds), 2, '0') << ":" <<
               fillString(std::to_string(milliseconds), 3, '0');

    // TODO Make better info presentation
    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    timeString.str().c_str(), purple, black, 1, 26);
    drawLocation.shift(0, fontSize + textPaddingSize);

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    ("Gen: " + std::to_string(gameBoard.getGeneration())).c_str(), purple, black, 1, 26);
    drawLocation.shift(0, fontSize + textPaddingSize);
    
    unsigned int realFps;

    unsigned int secondsPassed = (unsigned int) std::chrono::duration_cast<std::chrono::seconds>(stopwatch.getDuration()).count();
    unsigned int framesPassed = gameBoard.getGeneration();
    realFps = framesPassed / (secondsPassed < 1 ? 1 : secondsPassed );
    

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    ("FPS: " + std::to_string(fps) + " (" + std::to_string(realFps) + ")").c_str(),
                    purple, black, 1, 26);
    drawLocation.shift(0, fontSize + textPaddingSize);

    if (stopwatch.isStopped()) {
        image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(), "Paused", purple, black, 1, 26);
        drawLocation.shift(0, fontSize + textPaddingSize);
    }

    std::map<std::string, std::string> controllers {
            {"FPS UP",       "num+"},
            {"FPS DOWN",     "num-"},
            {"STOP / START", "space / enter"},
            {"EXIT",         "esc / q"},
    };

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    std::string("Control:").c_str(), purple, black, 1, 26);
    drawLocation.shift(0, fontSize + textPaddingSize);

    Point controllersLocation(drawLocation);
    controllersLocation.shift(32, 0);

    for (auto controller : controllers) {
        image.draw_text((const int) controllersLocation.getX(),
                        (const int) controllersLocation.getY(),
                        std::string(controller.first).c_str(),
                        purple, black, 1, 26);

        image.draw_text((const int) controllersLocation.getX() + 128 + 48,
                        (const int) controllersLocation.getY(),
                        std::string(controller.second).c_str(),
                        purple, black, 1, 26);

        controllersLocation.shift(0, fontSize + textPaddingSize);
    }

}

