#pragma once

#include "Shape.h"
#include "Point.h"

#define PI 3.14

class Circle : public Shape
{
public:
	Circle(const Point&, double);
	~Circle();

	Point getCenter() const;
	double getRadius() const;

	virtual double area() const;
	virtual double perimeter() const;
	virtual void draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]);

private:
	Point _center;
	double _radius;
};