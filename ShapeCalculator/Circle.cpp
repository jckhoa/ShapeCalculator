#include "Circle.h"
#include <sstream>

Circle::Circle() : radius(0.) {}

Circle::Circle(double radius) : radius(radius) {}

Circle::~Circle() {}

void Circle::setSize(double radius) {
	this->radius = radius;
}

// Return the number of double value used in serialized input
size_t Circle::getSerializationSize() const {
	return 1;
}

// Set input data from serialied double values
void Circle::setSize(const std::vector<double>& serializedInput) {
	std::vector<double> data(serializedInput);
	data.resize(getSerializationSize(), 0.);
	radius = data[0];
}

double Circle::getRadius() const {
	return radius;
}

ShapeType Circle::getClassShapeType() {
	return ShapeType::Circle;
}

ShapeType Circle::getShapeType() const {
	return ShapeType::Circle;
};

double Circle::getPerimeter() const {
	if (!isValid()) return 0.;
	return radius * M_PI * 2;
}

double Circle::getArea() const {
	if (!isValid()) return 0.;
	return radius * radius * M_PI;
}

bool Circle::isValid() const {
	return radius > 0;
}

std::string Circle::toString() const {
	std::stringstream ss;
	ss << "Circle(radius=" << radius << ")";
	return ss.str();
}