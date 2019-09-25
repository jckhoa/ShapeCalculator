#include "Rectangle.h"

Rectangle::Rectangle() : width(0.), height(0.) {}

Rectangle::Rectangle(double width, double height) : width(width), height(height) {

}

void Rectangle::setSize(double width, double height) {
	this->width = width;
	this->height = height;
}

double Rectangle::getWidth() {
	return width;
}

double Rectangle::getHeight() {
	return height;
}

bool Rectangle::isSquare() {
	return width == height;
}

ShapeType Rectangle::getClassShapeType() {
	return ShapeType::Rectangle;
}

ShapeType Rectangle::getShapeType() {
	return ShapeType::Rectangle;
};

double Rectangle::getPerimeter() {
	if (!isValid()) return 0.;
	return (width + height) * 2;
}

double Rectangle::getArea() {
	if (!isValid()) return 0.;
	return width * height;
}

bool Rectangle::isValid() {
	return width > 0 && height > 0;
}
