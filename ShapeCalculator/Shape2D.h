#pragma once

#include "Shape.h"
#include <sstream>

// The abstract class Shape2D is for implementing functions to compute geometrical properties of 2D shapes.

class Shape2D : public Shape {

public:

	// Compute and return the perimeter of the 2D shape
	virtual double getPerimeter() const = 0;

	// Compute and return the area of the 2D shape
	virtual double getArea() const = 0;

	// Return the string containing shape properties. Overload the function from class Shape
	std::string getPropertyString() const {
		std::stringstream ss;
		ss << "(perimeter=" << getPerimeter() << ",area=" << getArea() << ")";
		return ss.str();
	}

	// Destructor
	virtual ~Shape2D() {}
};