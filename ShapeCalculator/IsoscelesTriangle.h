#pragma once


#include "TriangleShape.h"

// The IsoscelesTriangle class describes an isosceles triangle with its side and base lengths.

class IsoscelesTriangle : public TriangleShape {

public:
	// Construct an isosceles triangle with side and base set to zero.
	IsoscelesTriangle();

	// Construct an isosceles triangle from side and base lengths.
	IsoscelesTriangle(double side, double base);

	// Destructor
	virtual ~IsoscelesTriangle();

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
	// Return 0. if the isosceles triangle is invalid.
	double getPerimeter();

	// Compute and return the area of the isosceles triangle
	// Return 0. if the isosceles triangle is invalid.
	double getArea();

	// Return true if the isoseles triangle is valid, i.e. valid condition for base and side lengths, false otherwise.
	bool isValid();

	// Return the string containing the shape info
	std::string toString();

private:

	double side; // side length of the isosceles triangle
	
	double base; // base length of the isoceles triangle
};