#include "Circle.h"

Circle::Circle() : radius(0.) {}

Circle::Circle(double radius) : radius(radius) {}

Circle::~Circle() {}

void Circle::setRadius(double radius) {
	this->radius = radius;
}

double Circle::getRadius() {
	return radius;
}

ShapeType Circle::getClassShapeType() {
	return ShapeType::Circle;
}

ShapeType Circle::getShapeType() {
	return ShapeType::Circle;
};

double Circle::getPerimeter() {
	if (!isValid()) return 0.;
	return radius * M_PI * 2;
}

double Circle::getArea() {
	if (!isValid()) return 0.;
	return radius * radius * M_PI;
}

bool Circle::isValid() {
	return radius > 0;
}

