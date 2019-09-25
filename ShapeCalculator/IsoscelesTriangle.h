#pragma once


#include "Shape2D.h"

// The IsoscelesTriangle class describes an isosceles triangle with its side and base lengths.

class IsoscelesTriangle : public Shape {

public:
	// Construct an isosceles triangle with side and base set to zero.
	IsoscelesTriangle() : side(0.), base(0.) {

	}

	// Construct an isosceles triangle from side and base lengths.
	IsoscelesTriangle(double side, double base) : side(side), base(base) {

	}

	// set the side and base lengths of the isosceles triangle
	void setSize(double side, double base) {
		this->side = side;
		this->base = base;
	}

	// get the side length of the isosceles triangle
	double getSide() {
		return side;
	}

	// get the base length of the isosceles triangle
	double getBase() {
		return base;
	}

	/////// Overriding functions ///////////

	double getPerimeter() {
		return side * 2 + base;
	}

	double getArea() {
		// compute height from Pythagore theorem
		double halfBase = base / 2;
		double height = sqrt(side * side - halfBase * halfBase);
		return halfBase * height;
	}

	bool isValid() {
		return (2 * side > base) && side > 0 && base > 0;
	}

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "IsoscelesTriangle";
	};

	static std::string getClassName() {
		return "IsoscelesTriangle";
	}
private:
	double side, base;
};