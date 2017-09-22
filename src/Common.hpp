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


using namespace cimg_library;

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
        if (imgDisplay.is_keyPADSUB()) {
            fps--;
        }

        // Mutex released
    }
    std::cout << "Thread killed";
}
