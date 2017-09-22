//
// Created by Steven on 9/22/2017.
//

#include <iostream>
#include <afxres.h>

const unsigned char
        purple[] = { 95, 39, 150 },
        red[] = { 0xff, 0, 0 },
        black[] = { 0, 0, 0 };

inline std::string fillString(std::string str, unsigned int desiredLength, char filler) {
    while (str.size() < desiredLength) {
        str = std::string(1, filler) + str;
    }
    return str;
}

inline void GetDesktopResolution(unsigned short& horizontal, unsigned short& vertical) {
    RECT desktop;
    // Get a handle to the desktop window
    const HWND hDesktop = GetDesktopWindow();
    // Get the size of screen to the variable desktop
    GetWindowRect(hDesktop, &desktop);
    horizontal = (unsigned short) desktop.right;
    vertical = (unsigned short) desktop.bottom;
}
