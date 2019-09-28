#include "Rectangle.h"
#include <sstream>

Rectangle::Rectangle() : width(0.), height(0.) {}

Rectangle::Rectangle(double width, double height) : width(width), height(height) {

}

Rectangle::~Rectangle() {}

void Rectangle::setSize(double width, double height) {
	this->width = width;
	this->height = height;
}

// Return the number of double value used in serialized input
size_t Rectangle::getSerializationSize() const {
	return 2;
}

// Set input data from serialied double values
void Rectangle::setSize(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	width = data[0];
	height = data[1];
}


double Rectangle::getWidth() const {
	return width;
}

double Rectangle::getHeight() const {
	return height;
}

bool Rectangle::isSquare() const {
	return width == height;
}

ShapeType Rectangle::getClassShapeType() {
	return ShapeType::Rectangle;
}

ShapeType Rectangle::getShapeType() const {
	return ShapeType::Rectangle;
};

double Rectangle::getPerimeter() const {
	if (!isValid()) return 0.;
	return (width + height) * 2;
}

double Rectangle::getArea() const {
	if (!isValid()) return 0.;
	return width * height;
}

bool Rectangle::isValid() const {
	return width > 0 && height > 0;
}

std::string Rectangle::toString() const {
	std::stringstream ss;
	ss << "Rectangle(width=" << width << ",height=" << height << ")";
	return ss.str();
}
