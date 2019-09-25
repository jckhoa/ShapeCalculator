#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <string>


// The abstract class Shape for defining all 2D and 3D shapes

class Shape {
public:

	// Return the name of the shape
	virtual std::string getShapeName() { 
		return "Shape"; 
	};

	// Convert to the final derived classes (casting from Base to Derived)
	template <class T>
	operator T*() {
		// Type checking by name
		if (getShapeName().compare(T::getClassName()) == 0) {
			return static_cast<T*>(this);
		}
		else {
			return nullptr;
		}
	}

	// Convert to the final derived classes  (casting from Base to Derived)
	template <class T>
	operator T&() {
		// Type checking by name
		if (getShapeName().compare(T::getClassName()) == 0) {
			return static_cast<T&>(*this);
		}
	}

	// Check and return if the shape is valid
	// For example:
	// A valid triangle whose edge lengths are a,b, and c must satisfy 3 following conditions:
	// a + b > c
	// a + c > b
	// b + c > a
	// If at least one of the condition is not met for a triangle, the function must return false.
	virtual bool isValid() = 0;

	// Destructor
	virtual ~Shape() {}
};