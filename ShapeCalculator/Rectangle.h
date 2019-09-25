#pragma once

#include "RectangleShape.h"

// The Rectangle class describes a rectangle with its width and height.

class Rectangle : public RectangleShape {
public:

	// Construct a rectangle with width and height set to zeros.
	Rectangle();

	// Construct a rectangle from width and height values
	Rectangle(double width, double height);

	// Desctructor
	virtual ~Rectangle();

	// Set the width and height of the rectangle
	void setSize(double width, double height);

	// Return the width of the rectangle
	double getWidth();

	// Return the height of the rectangle
	double getHeight();

	// Return true if this rectangle is a square (width is equal to height), false otherwise.
	bool isSquare();

	// return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions ///////////

	// Return the shape type of the object
	ShapeType getShapeType();

	// Compute and return the perimeter of the rectangle.
	// Return 0. if the rectangle is invalid.
	double getPerimeter();

	// Compute and return the area of the rectangle.
	// Return 0. if the rectangle is invalid.
	double getArea();

	// Return true if the rectangle is valid (width and height are positive), false otherwise.
	bool isValid();

private:

	double width; // width of the rectangle
	double height; // heigh of the rectangle
};