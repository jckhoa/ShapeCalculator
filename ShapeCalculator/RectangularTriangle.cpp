#include "RectangularTriangle.h"

RectangularTriangle::RectangularTriangle() : s1(0.), s2(0.) {

}

RectangularTriangle::RectangularTriangle(double side1, double side2) : s1(side1), s2(side2) {

}

RectangularTriangle::~RectangularTriangle() {}

void RectangularTriangle::setSize(double side1, double side2) {
	this->s1 = side1;
	this->s2 = side2;
}

double RectangularTriangle::getFirstSide() {
	return s1;
}

double RectangularTriangle::getSecondSide() {
	return s2;
}

ShapeType RectangularTriangle::getClassShapeType() {
	return ShapeType::RectangularTriangle;
}

ShapeType RectangularTriangle::getShapeType() {
	return ShapeType::RectangularTriangle;
};

double RectangularTriangle::getPerimeter() {
	if (!isValid()) return 0.;
	// using Pythagore theorem to compute the hypotenuse length
	double s3 = sqrt(s1 * s1 + s2 * s2);
	return s1 + s2 + s3;
}

double RectangularTriangle::getArea() {
	if (!isValid()) return 0.;
	return s1 * s2 / 2;
}

bool RectangularTriangle::isValid() {
	return s1 > 0 && s2 > 0;
}
