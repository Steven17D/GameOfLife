#include "Quadrangle.h"

using namespace cimg_library;

Quadrangle::Quadrangle(Point a, Point b, Point c, Point d){
	_points.reserve(4);
	_points.push_back(a);
	_points.push_back(b);
	_points.push_back(c);
	_points.push_back(d);
}

Quadrangle::~Quadrangle(){
	
}

double Quadrangle::area() const{
	double sum = 0;
	for (int i = 0; i < 4; i++){
		if (i != 3){
			sum += (_points[i].getX() * _points[i + 1].getY()) - (_points[i].getY() * _points[i + 1].getX());
		}
		else{
			sum += (_points[i].getX() * _points[0].getY()) - (_points[i].getY() * _points[0].getX());
		}
	}
	return (sum > 0.0) ? sum / 2.0 : sum / -2.0;

}

double distance(Point a, Point b){
	return sqrt(pow((a.getY() - b.getY()), 2) + pow((a.getX() - b.getX()), 2));
}

void Quadrangle::draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]){
	CImg<int> points(4, 2);
	for (unsigned int i = 0; i < 4; i++){
		points(i, 0) = (int) _points[i].getX();
		points(i, 1) = (int) _points[i].getY();
	}
	canvas.draw_polygon(points, color);
}