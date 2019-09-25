#pragma once

#include "Shape2D.h"

// The Rectangle class describes a rectangle with its width and height.

class Rectangle : public Shape {
public:

	// Construct a rectangle with width and height set to zeros.
	Rectangle() : width(0.), height(0.) {}

	// Construct a rectangle from width and height values
	Rectangle(double width, double height) : width(width), height(height) {

	}

	void setSize(double width, double height) {
		this->width = width;
		this->height = height;
	}

	double getWidth() {
		return width;
	}

	double getHeight() {
		return height;
	}

	bool isSquare() {
		return width == height;
	}

	/////// Overriding functions ///////////

	double getPerimeter() {
		return (width + height) * 2;
	}

	double getArea() {
		return width * height;
	}

	bool isValid() {
		return width > 0 && height > 0;
	}

	// Return the name of the shape
	virtual std::string getShapeName() {
		return "Rectangle";
	};

	static std::string getClassName() {
		return "Rectangle";
	}
private:
	double width, height;
};