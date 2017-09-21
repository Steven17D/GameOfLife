#include "Circle.h"

Circle::Circle(const Point& p, double r) : _center(p){
	_radius = r;
}

Circle::~Circle(){
	
}


Point Circle::getCenter() const{
	return _center;
}

double Circle::getRadius() const{
	return _radius;
}


double Circle::area() const{
	return pow(_radius, 2) * atan(1) * 4;
}

double Circle::perimeter() const{
	return atan(1) * 8 * _radius;
}

void Circle::draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]){
    canvas.draw_circle(_center.getX(), _center.getY(), _radius, color);
}