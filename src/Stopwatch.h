//
// Created by Steven on 9/22/2017.
//

#ifndef GAMEOFLIFE_STOPWATCH_H
#define GAMEOFLIFE_STOPWATCH_H


#include <chrono>

class Stopwatch {
public:
    void start();
    void stop();
    void reset();

    bool isStopped(){ return stopped;}

    std::chrono::high_resolution_clock::duration getDuration();

private:
    std::chrono::high_resolution_clock::duration duration = std::chrono::high_resolution_clock::duration::zero();
    std::chrono::high_resolution_clock::time_point startTime;

    bool stopped = true;
};


#endif //GAMEOFLIFE_STOPWATCH_H
