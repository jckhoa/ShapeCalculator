#include "Square.h"
#include <sstream>

Square::Square() : side(0.) {

}

Square::Square(double sideLength) : side(sideLength) {

}

Square::~Square() {}

void Square::setSize(double sideLength) {
	side = sideLength;
}

// Return the number of double value used in serialized input
size_t Square::getSerializationSize() const {
	return 1;
}

// Set input data from serialied double values
void Square::setSize(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	side = data[0];
}

double Square::getSide() const {
	return side;
}

ShapeType Square::getClassShapeType() {
	return ShapeType::Square;
}

ShapeType Square::getShapeType() const {
	return ShapeType::Square;
};

double Square::getPerimeter() const {
	if (!isValid()) return 0.;
	return side * 4;
}

double Square::getArea() const {
	if (!isValid()) return 0.;
	return side * side;
}

bool Square::isValid() const {
	return side > 0;
}

std::string Square::toString() const {
	std::stringstream ss;
	ss << "Square(side=" << side << ")";
	return ss.str();
}