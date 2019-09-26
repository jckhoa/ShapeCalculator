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
