//
// Created by Steven on 9/22/2017.
//

#include "Patterns.h"



const Grid Patterns::glider = {
        {DEAD, LIVE, DEAD},
        {DEAD, LIVE, LIVE},
        {LIVE, DEAD, LIVE}
};

const Grid Patterns::queenBeeShuttle = {
        {LIVE, LIVE, DEAD, DEAD},
        {DEAD, DEAD, LIVE, DEAD},
        {DEAD, DEAD, DEAD, LIVE},
        {DEAD, DEAD, DEAD, LIVE},
        {DEAD, DEAD, DEAD, LIVE},
        {DEAD, DEAD, LIVE, DEAD},
        {LIVE, LIVE, DEAD, DEAD}
};

const Grid Patterns::objectLightWeight = {
        {LIVE, DEAD, DEAD, LIVE, DEAD},
        {DEAD, DEAD, DEAD, DEAD, LIVE},
        {LIVE, DEAD, DEAD, DEAD, LIVE},
        {DEAD, LIVE, LIVE, LIVE, LIVE}
};
const Grid Patterns::objectMediumWeight = {
        {DEAD, DEAD, LIVE, DEAD, DEAD, DEAD},
        {LIVE, DEAD, DEAD, DEAD, LIVE, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD, LIVE},
        {LIVE, DEAD, DEAD, DEAD, DEAD, LIVE},
        {DEAD, LIVE, LIVE, LIVE, LIVE, LIVE}
};

const Grid Patterns::objectHeavyWeight = {
        {DEAD, DEAD, LIVE, LIVE, DEAD, DEAD, DEAD},
        {LIVE, DEAD, DEAD, DEAD, DEAD, LIVE, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD, DEAD, LIVE},
        {LIVE, DEAD, DEAD, DEAD, DEAD, DEAD, LIVE},
        {DEAD, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE}
};

const Grid Patterns::blinker = {
        {LIVE, LIVE, LIVE}
};

const Grid Patterns::toad = {
        {DEAD, LIVE, LIVE, LIVE},
        {LIVE, LIVE, LIVE, DEAD}
};

const Grid Patterns::oscillator = {
        {LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE, LIVE}
};

const Grid Patterns::prettyOscillator = {
        {DEAD, LIVE, DEAD},
        {LIVE, LIVE, LIVE},
        {LIVE, DEAD, LIVE},
        {LIVE, LIVE, LIVE},
        {DEAD, LIVE, DEAD},
};

const Grid Patterns::tumbler = {
        {DEAD, LIVE, LIVE, DEAD, LIVE, LIVE, DEAD},
        {DEAD, LIVE, LIVE, DEAD, LIVE, LIVE, DEAD},
        {DEAD, DEAD, LIVE, DEAD, LIVE, DEAD, DEAD},
        {LIVE, DEAD, LIVE, DEAD, LIVE, DEAD, LIVE},
        {LIVE, DEAD, LIVE, DEAD, LIVE, DEAD, LIVE},
        {LIVE, LIVE, DEAD, DEAD, DEAD, LIVE, LIVE},
};

const Grid Patterns::gosperGliderGun = {
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, LIVE, LIVE,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, LIVE,   LIVE, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, LIVE, DEAD, LIVE,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, LIVE,   LIVE, DEAD, DEAD},
        {LIVE, LIVE, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, LIVE,   LIVE, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, LIVE, LIVE, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {LIVE, LIVE, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, LIVE, DEAD,   LIVE, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, LIVE, LIVE,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, LIVE, LIVE, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, LIVE, DEAD, LIVE, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, LIVE, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   LIVE, LIVE, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   LIVE, DEAD, LIVE},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   LIVE, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, LIVE,   LIVE, LIVE, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, LIVE,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD},
        {DEAD, DEAD, DEAD, DEAD, DEAD,  DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   LIVE, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD, DEAD, DEAD,   DEAD, DEAD, DEAD}
};

const Grid Patterns::block = {
        {LIVE, LIVE},
        {LIVE, LIVE}
};

const Grid Patterns::beehive = {
        {DEAD, LIVE, DEAD},
        {LIVE, DEAD, LIVE},
        {LIVE, DEAD, LIVE},
        {DEAD, LIVE, DEAD}
};

const Grid Patterns::boat = {
        {DEAD, LIVE, DEAD},
        {LIVE, DEAD, LIVE},
        {DEAD, LIVE, LIVE}
};

const Grid Patterns::ship = {
        {LIVE, LIVE, DEAD},
        {LIVE, DEAD, LIVE},
        {DEAD, LIVE, LIVE}
};

const Grid Patterns::loaf = {
        {DEAD, LIVE, LIVE, DEAD},
        {LIVE, DEAD, DEAD, LIVE},
        {DEAD, LIVE, DEAD, LIVE},
        {DEAD, DEAD, LIVE, DEAD}
};