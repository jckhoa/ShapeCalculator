#pragma once

#include "RectangleShape.h"


// The Square class describes a square with its side length.

class Square : public RectangleShape {
public:
	// Construct a square with side lengths set to zeros.
	Square();

	// Construct a square from side length value.
	Square(double sideLength);

	// Destructor
	virtual ~Square();

	// Set side length of the square
	void setSize(double sideLength);

	// Get side length of the square
	double getSide() const;

	// return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions ///////////

	// Return the shape type of the object
	ShapeType getShapeType() const;

	// Compute and return the perimeter of the square
	// Return 0. if the square is invalid.
	double getPerimeter() const;

	// Compute and return the area of the square
	// Return 0. if the square is invalid.
	double getArea() const;

	// Return true if the square is valid (side length is positive), false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string toString() const;

private:

	double side; // side length of the square

};