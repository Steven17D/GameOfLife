#pragma once

#include "Polygon.h"

class Quadrangle : public Polygon
{
public:
	Quadrangle(Point, Point, Point, Point);
	~Quadrangle();
	virtual void draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]);


	virtual double area() const;
private:

};