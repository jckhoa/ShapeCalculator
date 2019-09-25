#pragma once

#include "Circle.h"

// The Donut (or Couronne) class describes a donut shape with two concentric circles.

class Donut : public Shape {

public:
	// Construct a donut with the internal and external radii set to zeros.
	Donut();

	// Construct a donut from the internal and external radii. Their order is not important.
	Donut(double radius1, double radius2);

	// Desctructor
	virtual ~Donut();

	// Set the internal and external radii. Their order is not important.
	void setSize(double radius1, double radius2);

	// Return the internal radius of the donut.
	double getInternalRadius();

	// Return the external radius of the donut.
	double getExternalRadius();

	// Return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions from base classes ///////////

	// Return the shape type of the object
	ShapeType getShapeType();

	// Compute and return the perimeter of the donut
	// Return 0. if the donut is invalid.
	double getPerimeter();

	// Compute and return the area of the donut
	// Return 0. if the donut is invalid.
	double getArea();

	// Return true if the donut is valid (i.e. the internal and external circle are valid and their outlines do not overlap), false otherwise
	bool isValid();

private:
	Circle ci; // internal circle
	Circle ce; // external circle
};