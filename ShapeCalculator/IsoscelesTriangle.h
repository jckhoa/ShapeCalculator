#pragma once


#include "Shape2D.h"

// The IsoscelesTriangle class describes an isosceles triangle with its side and base lengths.

class IsoscelesTriangle : public Shape {

public:
	// Construct an isosceles triangle with side and base set to zero.
	IsoscelesTriangle();

	// Construct an isosceles triangle from side and base lengths.
	IsoscelesTriangle(double side, double base);

	// Set the side and base lengths of the isosceles triangle
	void setSize(double side, double base);

	// Return the side length of the isosceles triangle
	double getSide();

	// Return the base length of the isosceles triangle
	double getBase();

	// Return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions ///////////
	
	// Return the shape type of the object
	ShapeType getShapeType();

	// Compute and return the perimeter of the isosceles triangle
	double getPerimeter();

	// Compute and return the area of the isosceles triangle
	double getArea();

	// Return true if the isoseles triangle is valid, i.e. valid condition for base and side lengths, false otherwise.
	bool isValid();

private:

	double side; // side length of the isosceles triangle
	
	double base; // base length of the isoceles triangle
};