//
// Created by Steven on 9/22/2017.
//

#ifndef GAMEOFLIFE_PATTERNS_H
#define GAMEOFLIFE_PATTERNS_H

#include "GameBoard.h"

struct Patterns {
    const static Grid glider;
    const static Grid queenBeeShuttle;

    const static Grid objectLightWeight;
    const static Grid objectMediumWeight;
    const static Grid objectHeavyWeight;

    const static Grid blinker;
    const static Grid toad;

    const static Grid oscillator;
    const static Grid prettyOscillator;
    const static Grid tumbler;
    const static Grid gosperGliderGun;

    const static Grid block;
    const static Grid beehive;
    const static Grid boat;
    const static Grid ship;
    const static Grid loaf;
};

#endif //GAMEOFLIFE_PATTERNS_H
