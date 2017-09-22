//
// Created by Steven on 9/22/2017.
//

#include "GameController.h"

GameController::GameController(cimg_library::CImgDisplay& imgDisplay,
                               Stopwatch& stopwatch,
                               bool& showCenter, bool& threadAlive,
                               unsigned short& fps) :
        imgDisplay(imgDisplay), stopwatch(stopwatch), showCenter(showCenter), threadAlive(threadAlive), fps(fps) {

}

void GameController::start() {
    std::thread keyboardControlThread(&GameController::KeyboardControl, this, std::ref(imgDisplay),
                                      std::ref(stopwatch), std::ref(showCenter), std::ref(fps),
                                      std::ref(threadAlive));
    keyboardControlThread.detach();
}

void GameController::KeyboardControl(cimg_library::CImgDisplay &imgDisplay, Stopwatch &stopwatch, bool &showCenter,
                                     unsigned short &fps, bool &threadAlive) {
    std::mutex mutex;
    while (threadAlive){
        imgDisplay.wait();  // Wait for input
        std::lock_guard<std::mutex> lock(mutex);
        // Mutex locked
        if (imgDisplay.is_keySPACE() || imgDisplay.is_keyENTER()) {
            if (stopwatch.isStopped())
                stopwatch.start();
            else
                stopwatch.stop();
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
}
