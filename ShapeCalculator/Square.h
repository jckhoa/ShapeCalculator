#pragma once

#include "Shape2D.h"


// The Square class describes a square with its side length.

class Square : public Shape {
public:
	// Construct a square with side lengths set to zeros.
	Square() : side(0.) {}

	// Construct a square from side length value.
	Square(double sideLength) : side(sideLength) {

	}

	// Set side length of the square
	void setSideLength(double sideLength) {
		side = sideLength;
	}

	// Get side length of the square
	double getSideLength() {
		return side;
	}

	/////// Overriding functions ///////////

	double getPerimeter() {
		return side * 4;
	}

	double getArea() {
		return side * side;
	}

	bool isValid() {
		return side > 0;
	}

	// Return the shape type of the object
	ShapeType getShapeType() {
		return ShapeType::Square;
	};

	// return the shape type of the class
	static ShapeType getClassShapeType() {
		return ShapeType::Square;
	}
private:
	double side;
};