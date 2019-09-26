#pragma once

#include "CircleShape.h"


// The Circle (or Disque) class describes a circular shape with a radius.

class Circle : public CircleShape {

public:

	// Construct a circle with a radius of zero.
	Circle();

	// Construct a circle from the radius value.
	Circle(double radius);

	// Desctructor
	virtual ~Circle();

	// Set the radius of the circle
	void setSize(double radius);

	// Return the radius of the circle
	double getRadius() const;

	// Return the shape type of the class
	static ShapeType getClassShapeType();

	/////// Overriding functions from base classes ///////////

	// Return the shape type of the object
	ShapeType getShapeType() const;

	// Compute and return the perimeter of the circle.
	// Return 0. if the circle is invalid.
	double getPerimeter() const;

	// Compute and return the area of the circle
	// Return 0. if the circle is invalid.
	double getArea() const;

	// Return true if the circle is valid (the radius is positive), false otherwise.
	bool isValid() const;

	// Return the string containing the shape info
	std::string toString() const;

private:

	// Radius of the circle
	double radius;

};