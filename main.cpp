#include <Windows.h>
#include <iostream>
#include "GameBoard.h"
#include "mingw.mutex.h"
#include "mingw.thread.h"

using namespace cimg_library;
std::mutex mutex;

// Get the horizontal and vertical screen sizes in pixel
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

void KeyboardControl(CImgDisplay& imgDisplay , bool& paused, bool& threadAlive){
    while (threadAlive){
        std::lock_guard<std::mutex> lock(mutex);
        if (imgDisplay.is_keySPACE() || imgDisplay.is_keyENTER()) {
            paused = !paused;
        }
        if (imgDisplay.is_keyESC() || imgDisplay.is_keyQ()) {
            threadAlive = false;
            imgDisplay.close();
        }
    }
    std::cout << "thread killed";
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    const unsigned char
            purple[] = { 95, 39, 150 },
            black[] = { 0, 0, 0 };

    unsigned short width, height;
    GetDesktopResolution(width, height);

    CImgDisplay imgDisplay(width, height, "Game Of Life", 3, true);

    const unsigned short size = 12;
    const unsigned short
            wCount = (const unsigned short) imgDisplay.width() / size,
            hCount = (const unsigned short) imgDisplay.height() / size;
    GameBoard gameBoard(wCount, hCount);

    Point location(wCount / 2, hCount / 2);
    std::cout << imgDisplay.width() << ", " << imgDisplay.height() << std::endl;

    gameBoard.initRandom();

    unsigned short generation = 1;
    bool paused = true;
    bool threadAlive = true;

    std::thread t(&KeyboardControl,  std::ref(imgDisplay), std::ref(paused), std::ref(threadAlive));
    t.detach();

    do {

        CImg<unsigned char> image((const unsigned int) imgDisplay.width(), (const unsigned int) imgDisplay.height(), 1, 3, 1);

        gameBoard.draw(image, purple);
        image.draw_text(10, 10, std::to_string(generation).c_str(), purple, black, 1, 26);

        if (!paused) {
            gameBoard.next();
            generation++;
        } else {
            image.draw_text(10, 40, "Paused", purple, black, 1, 26);
        }

        imgDisplay.display(image);
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    } while (!imgDisplay.is_closed());

    threadAlive = false;

    return 0;
}