#pragma once

#include "Shape.h"



// The abstract class Shape3D is for implementing the functions to compute geometrical properties of 3D shapes

class Shape3D : public Shape {

public:

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "Shape3D";
	};

	// Compute and return the volume of the 3D shape.
	virtual double getVolume() = 0;

	// Compute and return the surface area of the 3D shape.
	virtual double getSurfaceArea() = 0;

	// Destructor
	virtual ~Shape3D() {}
};