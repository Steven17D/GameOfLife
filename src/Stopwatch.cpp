//
// Created by Steven on 9/22/2017.
//

#include "Stopwatch.h"

void Stopwatch::start() {
    if (stopped) {
        startTime = std::chrono::high_resolution_clock::now();
        stopped = false;
    }
}

void Stopwatch::stop() {
    if (!stopped){
        duration += (std::chrono::high_resolution_clock::now() - startTime);
        stopped = true;
    }
}

void Stopwatch::reset() {
    duration = std::chrono::high_resolution_clock::duration::zero();
}

std::chrono::high_resolution_clock::duration Stopwatch::getDuration() {
    std::chrono::high_resolution_clock::duration currentDuration = std::chrono::high_resolution_clock::duration::zero();
    if (!stopped) {
        currentDuration = std::chrono::high_resolution_clock::now() - startTime;
    }
    return duration + currentDuration;
}
