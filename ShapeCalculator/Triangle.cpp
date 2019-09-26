#include "Triangle.h"
#include <sstream>

Triangle::Triangle() : a(0.), b(0.), c(0.) {

}

Triangle::Triangle(double side1, double side2, double side3) : a(side1), b(side2), c(side3) {

}

Triangle::~Triangle() {}

void Triangle::setSize(double side1, double side2, double side3) {
	a = side1;
	b = side2;
	c = side3;
}

double Triangle::getFirstSide() const {
	return a;
}

double Triangle::getSecondSide() const {
	return b;
}

double Triangle::getThirdSide() const {
	return c;
}

ShapeType Triangle::getClassShapeType() {
	return ShapeType::Triangle;
}

ShapeType Triangle::getShapeType() const {
	return ShapeType::Triangle;
};

double Triangle::getPerimeter() const {
	if (!isValid()) return 0.;
	return a + b + c;
}

double Triangle::getArea() const {
	// Return 0. if the triangle is invalid
	if (!isValid()) return 0.;

	// Use Heron's formula to compute its area
	double p = getPerimeter() / 2; // compute half perimeter
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

bool Triangle::isValid() const {
	return (a + b > c) && (a + c > b) && (b + c > a);
}

std::string Triangle::toString() const {
	std::stringstream ss;
	ss << "Triangle(side1=" << a << ",side2=" << b << ",side3=" << c << ")";
	return ss.str();
}