#pragma once

#include "Shape2D.h"


// The Square class describes a square with its side length.

class Square : public Shape {
public:
	// Construct a square with side lengths set to zeros.
	Square();

	// Construct a square from side length value.
	Square(double sideLength);

	// Set side length of the square
	void setSideLength(double sideLength);

	// Get side length of the square
	double getSideLength();

	// return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions ///////////

	// Return the shape type of the object
	ShapeType getShapeType();

	// Compute and return the perimeter of the square
	// Return 0. if the square is invalid.
	double getPerimeter();

	// Compute and return the area of the square
	// Return 0. if the square is invalid.
	double getArea();

	// Return true if the square is valid (side length is positive), false otherwise.
	bool isValid();

private:
	double side;
};