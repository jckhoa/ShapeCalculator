#pragma once

#include "Shape.h"
#include <sstream>

// The abstract class Shape3D is for implementing the functions to compute geometrical properties of 3D shapes

class Shape3D : public Shape {

public:

	// Compute and return the volume of the 3D shape.
	virtual double getVolume() const = 0;

	// Compute and return the surface area of the 3D shape.
	virtual double getSurfaceArea() const = 0;

	// Return the string containing shape properties. Overload the function from class Shape
	std::string getPropertyString() const {
		std::stringstream ss;
		ss << "(volume=" << getVolume() << ",surfaceArea=" << getSurfaceArea() << ")";
		return ss.str();
	}

	// Destructor
	virtual ~Shape3D() {}
};