#include "Polygon.h"

using namespace cimg_library;

Polygon::Polygon(){
	
}

Polygon::~Polygon(){
	
}

int Polygon::numOfPoints() const{
	return _points.size();
}

vector<Point> Polygon::getPoints() const{
	return _points;
}

vector<double> Polygon::getSides() const{
	vector<double> sides(_points.size());
	for (unsigned int i = 0; i < _points.size() - 1; i++){
		sides.push_back(distance(_points[i], _points[(i + 1)]));
	}
	sides.push_back(distance(_points[_points.size() - 1], _points[0]));
	return sides;
}


double Polygon::perimeter() const{
	double p = 0;
	vector<double> sides = this->getSides();
	for (unsigned int i = 0; i < sides.size(); i++){
		p += (double)sides[i];
	}
	return p;
}

double Polygon::distance(Point a, Point b) const{
	return sqrt(pow((a.getY() - b.getY()), 2) + pow((a.getX() - b.getX()), 2));
}

void Polygon::draw(cimg_library::CImg<unsigned char>& canvas, const unsigned char color[3]){
	//CImg<unsigned char> points();
	//board.draw_polygon(points, color);
}