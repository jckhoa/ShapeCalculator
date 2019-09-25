#pragma once

#include "Shape2D.h"


// The Circle (or Disque) class describes a circular shape with a radius.

class Circle : public Shape2D {

public:
	// Construct a circle with a radius of zero.
	Circle() : radius(0.) {}

	// Construct a circle from the radius value.
	Circle(double radius) : radius(radius) {}

	// Set the radius of the circle
	void setRadius(double radius) {
		this->radius = radius;
	}

	// Get the radius of the circle
	double getRadius() {
		return radius;
	}


	/////// Overriding functions ///////////

	double getPerimeter() {
		return radius * M_PI * 2;
	}

	double getArea() {
		return radius * radius * M_PI;
	}

	bool isValid() {
		return radius > 0;
	}

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "Circle";
	};

	static std::string getClassName() {
		return "Circle";
	}
private:

	double radius; // radius of the circle
};