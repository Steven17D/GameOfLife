//
// Created by Steven on 9/22/2017.
//

#include <windows.h>
#include <iostream>
#include <sstream>
#include "GameBoard.h"
#include "mingw.mutex.h"
#include "mingw.thread.h"
#include "Patterns.h"
#include "Stopwatch.h"


using namespace cimg_library;


const unsigned char
        purple[] = { 95, 39, 150 },
        red[] = { 0xff, 0, 0 },
        black[] = { 0, 0, 0 };

std::string fillString(std::string str, unsigned int desiredLength, char filler) {
    while (str.size() < desiredLength) {
        str = std::string(1, filler) + str;
    }
    return str;
}

void GetDesktopResolution(unsigned short& horizontal, unsigned short& vertical) {
    RECT desktop;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    // The top left corner will have coordinates (0,0)
    // and the bottom right corner will have coordinates
    // (horizontal, vertical)
    horizontal = (unsigned short) desktop.right;
    vertical = (unsigned short) desktop.bottom;
}

void KeyboardControl(CImgDisplay& imgDisplay ,
                     bool& paused, bool& showCenter, unsigned short& fps,
                     bool& threadAlive){
    std::mutex mutex;
    while (threadAlive){
        imgDisplay.wait();  // Wait for input
        std::lock_guard<std::mutex> lock(mutex);
        // Mutex locked
        if (imgDisplay.is_keySPACE() || imgDisplay.is_keyENTER()) {
            paused = !paused;
        }
        if (imgDisplay.is_keyESC() || imgDisplay.is_keyQ()) {
            threadAlive = false;
            imgDisplay.close();
        }
        if (imgDisplay.is_keyC()) {
            showCenter = !showCenter;
        }
        if (imgDisplay.is_keyPADADD()) {
            fps++;
        }
        if (imgDisplay.is_keyPADSUB() and fps > 1) {
            fps--;
        }

        // Mutex released
    }
    std::cout << "Thread killed";
}


void showInfo(GameBoard gameBoard, CImg<unsigned char>& image, unsigned short fps, Stopwatch stopwatch) {
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

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    ("FPS: " + std::to_string(fps)).c_str(), purple, black, 1, 26);
    drawLocation.shift(0, fontSize + textPaddingSize);

    if (stopwatch.isStopped()) {
        image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(), "Paused", purple, black, 1, 26);
        drawLocation.shift(0, fontSize + textPaddingSize);
    }

    image.draw_text((const int) drawLocation.getX(), (const int) drawLocation.getY(),
                    std::string("Control:\n"
                                        "\tspace STOP\n"
                                        "\tesc EXIT\n"
                                        "\tnum+ FPS UP\n"
                                        "\tnum- FPS DOWN\n").c_str(), purple, black, 1, 26);
    drawLocation.shift(0, fontSize + textPaddingSize);

}
