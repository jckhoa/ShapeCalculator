#pragma once

#include "Shape2D.h"

// The Triangle class describes a triangular shape with its 3 side lengths.

class Triangle: public Shape {
public:
	// Construct a triangle with all the side lengths of zeros.
	Triangle(): a(0.), b(0.), c(0.) {
	
	}

	// Construct a triangle with the length of 3 sides
	Triangle(double side1, double side2, double side3): a(side1), b(side2), c(side3) {
	
	}

	// Set the lengths of 3 sides of the triangle.
	void setSize(double side1, double side2, double side3) {
		a = side1;
		b = side2;
		c = side3;
	}

	// get the first side of the triangle
	double getFirstSide() {
		return a;
	}

	// get the second side of the triangle
	double getSecondSide() {
		return b;
	}

	// get the third side of the triangle
	double getThirdSide() {
		return c;
	}

	/////// Overriding functions ///////////

	double getPerimeter() {
		return a + b + c;
	}

	// compute the area of the triangle using Heron's formula
	double getArea() {
		if (!isValid()) return 0.;
		double p = getPerimeter() / 2; // compute half perimeter
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	bool isValid() {
		return (a + b > c) && (a + c > b) && (b + c > a);
	}

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "Triangle";
	};

	static std::string getClassName() {
		return "Triangle";
	}

private:
	double a, b, c; // three sides of the triangle
};