#pragma once

#include "Shape2D.h"


// The RectangleTriangle class describes a rectangle triangle with its side lengths.

class RectangularTriangle : public Shape {
public:
	// Construct a rectangular triangle with side lengths set to zeros.
	RectangularTriangle() : s1(0.), s2(0.) {

	}

	// Construct a rectangular triangle from its side lengths
	RectangularTriangle(double side1, double side2) : s1(side1), s2(side2) {

	}

	// set the side lengths of the rectangular triangle.
	void setSize(double side1, double side2) {
		this->s1 = side1;
		this->s2 = side2;
	}

	// get the first side length of the rectangular triangle.
	double getFirstSide() {
		return s1;
	}

	// get the second side length of the rectangular triangle.
	double getSecondSide() {
		return s2;
	}

	/////// Overriding functions ///////////

	double getPerimeter() {
		// using Pythagore theorem to compute the hypotenuse length
		double s3 = sqrt(s1 * s1 + s2 * s2);
		return s1 + s2 + s3;
	}

	double getArea() {
		return s1 * s2 / 2;
	}

	bool isValid() {
		return s1 > 0 && s2 > 0;
	}

	// Return the shape type of the object
	ShapeType getShapeType() {
		return ShapeType::RectangularTriangle;
	};

	// return the shape type of the class
	static ShapeType getClassShapeType() {
		return ShapeType::RectangularTriangle;
	}
private:
	double s1, s2;
};