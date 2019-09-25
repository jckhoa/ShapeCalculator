#include "Circle.h"

Circle::Circle() : radius(0.) {}

Circle::Circle(double radius) : radius(radius) {}

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
	return radius * M_PI * 2;
}

double Circle::getArea() {
	return radius * radius * M_PI;
}

bool Circle::isValid() {
	return radius > 0;
}

