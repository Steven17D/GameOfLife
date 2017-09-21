//
// Created by Steven on 9/20/2017.
//

#ifndef GAMEOFLIFE_SHAPE_H
#define GAMEOFLIFE_SHAPE_H

#include "CImg.h"
#include <vector>
#include <math.h>


class Shape
{
public:
    virtual double perimeter() const = 0;
    virtual double area() const = 0;
    virtual void draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]) = 0;
private:
};

#endif //GAMEOFLIFE_SHAPE_H
