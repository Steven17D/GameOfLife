#include "Common.hpp"
//#include "Stopwatch.h"

int main() {
    const unsigned char
            purple[] = { 95, 39, 150 },
            red[] = { 0xff, 0, 0 },
            black[] = { 0, 0, 0 };

    unsigned short width, height;
    GetDesktopResolution(width, height);

    CImgDisplay imgDisplay(width, height, "Game Of Life", 3, true);

    unsigned short fps = 24;
    const unsigned short cellSize = 20;
    const unsigned short
            wCount = (const unsigned short) imgDisplay.width() / cellSize,
            hCount = (const unsigned short) imgDisplay.height() / cellSize;

    GameBoard gameBoard(wCount, hCount);

    Point location(wCount / 2, hCount / 2);
    std::cout << imgDisplay.width() << ", " << imgDisplay.height() << std::endl;

    // TODO add dialog for pattern choosing
//    gameBoard.initRandom();
    gameBoard.initPattern(Patterns::gosperGliderGun, location);

    bool paused = true,
            threadAlive = true,
            showCenter = false;

    std::thread t(&KeyboardControl,  std::ref(imgDisplay),
                  std::ref(paused), std::ref(showCenter), std::ref(fps),
                  std::ref(threadAlive));
    t.detach();
    auto start = std::chrono::high_resolution_clock::now();
    do {
        CImg<unsigned char> image((const unsigned int) imgDisplay.width(), (const unsigned int) imgDisplay.height(), 1, 3, 1);

        gameBoard.draw(image, purple);

        // TODO fix time to stop on pause
        auto deltaTime = std::chrono::high_resolution_clock::now() - start;
        auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(deltaTime).count() % 1000,
                seconds = std::chrono::duration_cast<std::chrono::seconds>(deltaTime).count() % 60,
                minutes = std::chrono::duration_cast<std::chrono::minutes>(deltaTime).count() % 60;

        std::ostringstream timeString;
        timeString << "Time: " <<
                   fillString(std::to_string(minutes), 2, '0') << ":" <<
                   fillString(std::to_string(seconds), 2, '0') << ":" <<
                   fillString(std::to_string(milliseconds), 3, '0');
        image.draw_text(10, 10, timeString.str().c_str(), purple, black, 1, 26);

        // TODO Make better info presentation
        image.draw_text(10, 10 + 26 + 4, ("Gen: " + std::to_string(gameBoard.getGeneration())).c_str(), purple, black, 1, 26);
        image.draw_text(10, 10 + 26 + 4 + 26 + 4, ("FPS: " + std::to_string(fps)).c_str(), purple, black, 1, 26);
        image.draw_text(10, 10 + 26 + 4 + 26 + 4 + 26 + 4, std::string("Control:\n"
                                                                               "\tspace STOP\n"
                                                                               "\tesc EXIT\n"
                                                                               "\tnum+ FPS UP\n"
                                                                               "\tnum- FPS DOWN\n").c_str(), purple, black, 1, 26);

        if (showCenter)
            image.draw_circle(imgDisplay.width() / 2, imgDisplay.height() / 2, 1, red);

        if (!paused) {
            image.draw_text(10, 40, "Paused", purple, black, 1, 26);
        }
        else {
            gameBoard.next();
        }

        imgDisplay.display(image);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    } while (!imgDisplay.is_closed());

    threadAlive = false;

    return 0;
}