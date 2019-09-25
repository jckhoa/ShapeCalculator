#include "Square.h"

Square::Square() : side(0.) {

}

Square::Square(double sideLength) : side(sideLength) {

}

Square::~Square() {}

void Square::setSize(double sideLength) {
	side = sideLength;
}

double Square::getSideLength() {
	return side;
}

ShapeType Square::getClassShapeType() {
	return ShapeType::Square;
}

ShapeType Square::getShapeType() {
	return ShapeType::Square;
};

double Square::getPerimeter() {
	if (!isValid()) return 0.;
	return side * 4;
}

double Square::getArea() {
	if (!isValid()) return 0.;
	return side * side;
}

bool Square::isValid() {
	return side > 0;
}