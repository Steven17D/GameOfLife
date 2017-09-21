//
// Created by Steven on 9/22/2017.
//

#ifndef GAMEOFLIFE_PATTERNS_H
#define GAMEOFLIFE_PATTERNS_H

#include "GameBoard.h"

struct Patterns {
    const Grid glider = {
            {DEAD, LIVE, DEAD},
            {DEAD, LIVE, LIVE},
            {LIVE, DEAD, LIVE}
    };

    const Grid queenBeeShuttle = {
            {LIVE, LIVE, DEAD, DEAD},
            {DEAD, DEAD, LIVE, DEAD},
            {DEAD, DEAD, DEAD, LIVE},
            {DEAD, DEAD, DEAD, LIVE},
            {DEAD, DEAD, DEAD, LIVE},
            {DEAD, DEAD, LIVE, DEAD},
            {LIVE, LIVE, DEAD, DEAD}
    };

    const Grid objectLightWeight = {
            {LIVE, DEAD, DEAD, LIVE, DEAD},
            {DEAD, DEAD, DEAD, DEAD, LIVE},
            {LIVE, DEAD, DEAD, DEAD, LIVE},
            {DEAD, LIVE, LIVE, LIVE, LIVE}
    };

    const Grid objectMediumWeight = {
            {DEAD, DEAD, LIVE, DEAD, DEAD, DEAD},
            {LIVE, DEAD, DEAD, DEAD, LIVE, DEAD},
            {DEAD, DEAD, DEAD, DEAD, DEAD, LIVE},
            {LIVE, DEAD, DEAD, DEAD, DEAD, LIVE},
            {DEAD, LIVE, LIVE, LIVE, LIVE, LIVE}
    };

    const Grid objectHeavyWeight = {
            {DEAD, DEAD, LIVE, LIVE, DEAD, DEAD, DEAD},
            {LIVE, DEAD, DEAD, DEAD, DEAD, LIVE, DEAD},
            {DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, LIVE},
            {LIVE, DEAD, DEAD, DEAD, DEAD, DEAD, LIVE},
            {DEAD, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE}
    };

    const Grid blinker = {
            {LIVE, LIVE, LIVE}
    };

    const Grid toad = {
            {DEAD, LIVE, LIVE, LIVE},
            {LIVE, LIVE, LIVE, DEAD}
    };

    const Grid oscillator = {
            {LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE}
    };

    const Grid prettyOscillator = {
            {DEAD, LIVE, DEAD},
            {LIVE, LIVE, LIVE},
            {LIVE, DEAD, LIVE},
            {LIVE, LIVE, LIVE},
            {DEAD, LIVE, DEAD},
    };

    const Grid block = {
            {LIVE, LIVE},
            {LIVE, LIVE}
    };

    const Grid beehive = {
            {DEAD, LIVE, DEAD},
            {LIVE, DEAD, LIVE},
            {LIVE, DEAD, LIVE},
            {DEAD, LIVE, DEAD}
    };

    const Grid boat = {
            {DEAD, LIVE, DEAD},
            {LIVE, DEAD, LIVE},
            {DEAD, LIVE, LIVE}
    };

    const Grid ship = {
            {LIVE, LIVE, DEAD},
            {LIVE, DEAD, LIVE},
            {DEAD, LIVE, LIVE}
    };

    const Grid loaf = {
            {DEAD, LIVE, LIVE, DEAD},
            {LIVE, DEAD, DEAD, LIVE},
            {DEAD, LIVE, DEAD, LIVE},
            {DEAD, DEAD, LIVE, DEAD}
    };
};

#endif //GAMEOFLIFE_PATTERNS_H
