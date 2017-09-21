#pragma once

#include "Shape.h"
#include "Point.h"
#include <iostream>
#include <vector>
#include "CImg.h"

using namespace std;

class Polygon : public Shape
{
public:
	Polygon();
	~Polygon();
	int numOfPoints() const;
	vector<Point> getPoints() const;
	vector<double> getSides() const;

	virtual double perimeter() const;
	virtual void draw(cimg_library::CImg<unsigned char>& canvas,  const unsigned char color[3]) = 0;

protected:
	double distance(Point a, Point b) const;
	std::vector<Point> _points;
};