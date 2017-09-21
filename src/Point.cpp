#include "Point.h"

Point::Point(double x, double y){
	_x = x;
	_y = y;
}

Point::Point(const Point& other){
	_x = other.getX();
	_y = other.getY();
}

Point::~Point(){
	
}


double Point::getX() const{
	return _x;
}

double Point::getY() const{
	return _y;
}

void Point::move(double x, double y){
	_x = x;
	_y = y;
}

void Point::shift(double x, double y){
	_x += x;
	_y += y;
}

void Point::move(const Point& other){
	_x = other.getX();
	_y = other.getY();
}

double Point::distance(const Point& other){
	return sqrt(pow((_x - other.getX()), 2) + pow((_y - other.getY()), 2));
}

void Point::draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]){
	canvas.draw_point(_x, _y, color);
}