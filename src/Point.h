#pragma once
#include <vector>
#include "CImg.h"

class Point
{
public:
	Point(double x, double y);
	Point(const Point& other);
	~Point();

	double getX() const;
	double getY() const;
	void move(double x, double y);
	void move(const Point& other);
    void shift(double x, double y);
	virtual double distance(const Point& other);
	virtual void draw(cimg_library::CImg<unsigned char>& canvas,  const unsigned char color[3]);

private:
	double _x;
	double _y;

};