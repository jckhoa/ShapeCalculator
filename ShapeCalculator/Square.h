#pragma once

#include "Shape2D.h"


// The Square class describes a square with its side length.

class Square : public Shape {
public:
	Square() : side(0.) {}

	Square(double sideLength) : side(sideLength) {

	}

	double getPerimeter() {
		return side * 4;
	}

	double getArea() {
		return side * side;
	}

	void setSideLength(double sideLength) {
		side = sideLength;
	}

	double getSideLength() {
		return side;
	}

	bool isValid() {
		return side > 0;
	}

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "Square";
	};

	static std::string getClassName() {
		return "Square";
	}
private:
	double side;
};