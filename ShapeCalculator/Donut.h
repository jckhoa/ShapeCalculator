#pragma once

#include "Circle.h"

// The Donut (or Couronne) class describes a donut shape with two concentric circles.

class Donut : public Shape {

public:
	// Construct a donut with the internal and external radii set to zeros.
	Donut() : ci(0.), ce(0.) {}

	// Construct a donut from the internal and external radii.
	// The order of the radius parameters is not important.
	Donut(double radius1, double radius2) {
		setSize(radius1, radius2);
	}

	// Set the internal and external radii.
	// The order of the radius parameters is not important.
	void setSize(double radius1, double radius2) {
		if (radius1 > radius2) {
			ci.setRadius(radius2);
			ce.setRadius(radius1);
		}
		else {
			ci.setRadius(radius1);
			ce.setRadius(radius2);
		}
	}

	// Get the internal radius of the donut.
	double getInternalRadius() {
		return ci.getRadius();
	}

	// Get the external radius of the donut.
	double getExternalRadius() {
		return ce.getRadius();
	}

	/////// Overriding functions ///////////

	double getPerimeter() {
		return ci.getPerimeter() + ce.getPerimeter();
	}

	double getArea() {
		double area = ci.getArea() - ce.getArea();
		return (area < 0) ? -area : area;
	}

	bool isValid() {
		return ci.isValid() && ce.isValid() && ci.getRadius() != ce.getRadius();
	}

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "Donut";
	};

	static std::string getClassName() {
		return "Donut";
	}
private:
	Circle ci; // internal circle
	Circle ce; // external circle
};