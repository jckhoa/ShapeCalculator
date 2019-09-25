#pragma once

#include "Shape2D.h"


// The Circle (or Disque) class describes a circular shape with a radius.

class Circle : public Shape2D {

public:

	// Construct a circle with a radius of zero.
	Circle();

	// Construct a circle from the radius value.
	Circle(double radius);

	// Set the radius of the circle
	void setRadius(double radius);

	// Return the radius of the circle
	double getRadius();

	// Return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions from base classes ///////////

	// Return the shape type of the object
	ShapeType getShapeType();

	// Compute and return the perimeter of the circle.
	// Return 0. if the circle is invalid.
	double getPerimeter();

	// Compute and return the area of the circle
	// Return 0. if the circle is invalid.
	double getArea();

	// Return true if the circle is valid (the radius is positive), false otherwise.
	bool isValid();

private:

	// Radius of the circle
	double radius;

};