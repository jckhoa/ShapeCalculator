#pragma once

#include "TriangleShape.h"

// The RectangleTriangle class describes a rectangle triangle with its side lengths.

class RectangularTriangle : public TriangleShape {

public:
	
	// Construct a rectangular triangle with side lengths set to zeros.
	RectangularTriangle();

	// Construct a rectangular triangle from its side lengths
	RectangularTriangle(double side1, double side2);

	// Desctructor
	virtual ~RectangularTriangle();

	// Set the side lengths of the rectangular triangle.
	void setSize(double side1, double side2);

	// Get the first side length of the rectangular triangle.
	double getFirstSide() const;

	// Get the second side length of the rectangular triangle.
	double getSecondSide() const;

	// Return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions ///////////
	
	// Return the shape type of the object
	ShapeType getShapeType() const;

	// Compute and return the perimeter of the rectangular triangle
	// Return 0. if the rectangular triangle is invalid.
	double getPerimeter() const;

	// Compute and return the area of the rectangular triangle
	// Return 0. if the rectangular triangle is invalid.
	double getArea() const;

	// Return true if the rectangular triangle is valid (both side lengths are positive), false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string toString() const;

private:

	double s1, s2; // side lengths of the rectangular triangle

};