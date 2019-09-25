#pragma once

#include "Shape2D.h"

// The Triangle class describes a triangular shape with its 3 side lengths.

class Triangle: public Shape {

public:
	// Construct a triangle with all the side lengths set to zeros.
	Triangle();

	// Construct a triangle with the length of 3 sides
	Triangle(double side1, double side2, double side3);

	// Set the lengths of 3 sides of the triangle.
	void setSize(double side1, double side2, double side3);

	// Return the first side of the triangle
	double getFirstSide();

	// Return the second side of the triangle
	double getSecondSide();

	// Return the third side of the triangle
	double getThirdSide();

	// return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions ///////////
	
	// Return the shape type of the object
	ShapeType getShapeType();

	// Compute and return the perimeter of the triangle.
	// Return 0. if the triangle is invalid.
	double getPerimeter();

	// Compute and return the area of the triangle.
	// Return 0. if the triangle is invalid.
	double getArea();

	// Return true if the triangle is valid, false otherwise.
	// A valid triangle with side lengths a, b, and c, must satisfy 3 following conditions
	// (1) a + b > c (2) a + c > b (3) b + c > a
	bool isValid();

private:
	double a, b, c; // three sides of the triangle
};