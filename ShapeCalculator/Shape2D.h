#pragma once

#include "Shape.h"

// The abstract class Shape2D is for implementing functions to compute geometrical properties of 2D shapes.
class Shape2D : public Shape {

public:

	// Compute and return the perimeter of the 2D shape
	virtual double getPerimeter() = 0;

	// Compute and return the area of the 2D shape
	virtual double getArea() = 0;

	// Destructor
	virtual ~Shape2D() {}
};