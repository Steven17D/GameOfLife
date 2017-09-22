#include "Common.hpp"

// TODO migrate all game logic to GameOfLife class
int main() {
    unsigned short width, height;
    GetDesktopResolution(width, height);

    Stopwatch stopwatch;
    CImgDisplay imgDisplay(width, height, "Game Of Life", 3, true);
    std::cout << imgDisplay.width() << ", " << imgDisplay.height() << std::endl;

    unsigned short fps = 24;
    const unsigned short cellSize = 20;
    const unsigned short
            wCount = (const unsigned short) imgDisplay.width() / cellSize,
            hCount = (const unsigned short) imgDisplay.height() / cellSize;

    GameBoard gameBoard(wCount, hCount);

    Point location(wCount / 2, hCount / 2);

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


    do {
        CImg<unsigned char> image((const unsigned int) imgDisplay.width(), (const unsigned int) imgDisplay.height(), 1, 3, 1);

        gameBoard.draw(image, purple);

        showInfo(gameBoard, image, fps, stopwatch);

        if (showCenter)
            image.draw_circle(imgDisplay.width() / 2, imgDisplay.height() / 2, 1, red);

        if (!paused) {
            stopwatch.stop();
        }
        else {
            gameBoard.next();
            stopwatch.start();
        }

        imgDisplay.display(image);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000 / fps));
    } while (!imgDisplay.is_closed());

    threadAlive = false;

    return 0;
}