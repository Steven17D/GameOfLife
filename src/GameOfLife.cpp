//
// Created by Steven on 9/22/2017.
//

#include "GameOfLife.h"
#include "Common.hpp"

#define SCREEN_MIDDLE_POINT Point(wCount/2, hCount/2)

GameOfLife::GameOfLife(unsigned short screenWidth, unsigned short screenHeight, unsigned short cellSize, unsigned short fps)
        : imgDisplay(screenWidth, screenHeight, "Game Of Life", 3, true),
          wCount((const unsigned short) imgDisplay.width() / cellSize),
          hCount((const unsigned short) imgDisplay.height() / cellSize),
          gameBoard(wCount,hCount),
          fps(fps), showCenter(false) { }

GameOfLife::~GameOfLife() = default;

void GameOfLife::start() {
    // TODO add dialog for pattern choosing
    gameBoard.initPattern(Patterns::gosperGliderGun, SCREEN_MIDDLE_POINT);

    GameController gameController(imgDisplay, gameBoard, stopwatch, showCenter, fps);
    std::thread frameRateCalculator(&GameOfLife::calculateFrameRate, this);
    Stopwatch autoCorrectStopwatch;

    stopwatch.start();
    gameController.start();
    frameRateCalculator.detach();
    autoCorrectStopwatch.start();

    do {
        autoCorrectStopwatch.reset();
        cimg_library::CImg<unsigned char> image(
                (const unsigned int) imgDisplay.width(), (const unsigned int) imgDisplay.height(), 1, 3, 1);
        gameBoard.draw(image, purple);
        showInfo(gameBoard, image);
        if (showCenter) image.draw_circle(imgDisplay.width() / 2, imgDisplay.height() / 2, 1, red);
        if (!stopwatch.isStopped()) gameBoard.next();
        imgDisplay.display(image);

        long long int millisecondsCount = (1000 / fps) - std::chrono::duration_cast<std::chrono::milliseconds>(autoCorrectStopwatch.getDuration()).count();
        if (millisecondsCount > 1)
            std::this_thread::sleep_for(std::chrono::milliseconds(millisecondsCount));
    } while (!imgDisplay.is_closed());
}

void GameOfLife::showInfo(const GameBoard &gameBoard, cimg_library::CImg<unsigned char> &image) {
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

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    timeString.str().c_str(), purple, black, 1, fontSize);
    drawLocation.shift(0, fontSize + textPaddingSize);

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    ("Gen: " + std::to_string(gameBoard.getGeneration())).c_str(), purple, black, 1, fontSize);
    drawLocation.shift(0, fontSize + textPaddingSize);

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    ("FPS: " + std::to_string(fps) +
                            " (" + std::to_string((unsigned short) realFps) + ")").c_str(),
                    purple, black, 1, fontSize);
    drawLocation.shift(0, fontSize + textPaddingSize);

    if (stopwatch.isStopped()) {
        image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(), "Paused", purple, black, 1, fontSize);
        drawLocation.shift(0, fontSize + textPaddingSize);
    }

    const std::map<std::string, std::string> controllers {
            {"CLEAR",        "X"},
            {"RESET",        "R"},
            {"FPS UP",       "NUM+"},
            {"FPS DOWN",     "NUM-"},
            {"STOP/START",   "SPACE"},
            {"EXIT",         "ESC"}
    };

    drawControllers(image, drawLocation, controllers, fontSize, textPaddingSize);
}

void GameOfLife::drawControllers(cimg_library::CImg<unsigned char> &image, Point drawLocation,
                                 std::map<std::string, std::string> controllers, const unsigned short fontSize,
                                 const unsigned short textPaddingSize) {
    const auto smallFontSize = (const unsigned short) (fontSize * 0.7f);
    // Draw title
    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    std::string("Control:").c_str(), purple, black, 1, fontSize);
    drawLocation.shift(16, fontSize + textPaddingSize);

    // Draw the controllers on real image
    for (auto controller : controllers) {
        image.draw_text((const int) drawLocation.getX(),
                        (const int) drawLocation.getY(),
                        std::string(controller.first).c_str(),
                        purple, black, 1, smallFontSize);

        image.draw_text((const int) drawLocation.getX() + 128,
                        (const int) drawLocation.getY(),
                        std::string(controller.second).c_str(),
                        purple, black, 1, smallFontSize);
        drawLocation.shift(0, smallFontSize + textPaddingSize);
    }
}

void GameOfLife::calculateFrameRate() {
    Stopwatch threadStopwatch;
    threadStopwatch.start();
    unsigned int millisecondsPassed;
    unsigned int framesPassed = gameBoard.getGeneration(), currentFrame;
    while (!imgDisplay.is_closed()) {
        millisecondsPassed = (unsigned int) std::chrono::duration_cast<std::chrono::milliseconds>(threadStopwatch.getDuration()).count();
        millisecondsPassed = millisecondsPassed < 1 ? 1 : millisecondsPassed;
        threadStopwatch.reset();
        currentFrame = gameBoard.getGeneration();
        realFps = (currentFrame - framesPassed) / (millisecondsPassed / 1000.0);
        framesPassed = currentFrame;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}
