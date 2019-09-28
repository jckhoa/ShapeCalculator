#pragma once

#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <vector>

#include "ShapeType.h"

// The abstract class Shape for defining all 2D and 3D shapes

class Shape {

public:

	// Destructor
	virtual ~Shape() {}

	// Return the number of double value used in serialized input
	virtual size_t getSerializationSize() const = 0;

	// Set input data from serialied double values
	virtual void setSize(std::vector<double>& serializedInput) = 0;
	
	// Check and return if the shape is valid
	// For example:
	// A valid triangle whose edge lengths are a,b, and c must satisfy 3 following conditions:
	// a + b > c
	// a + c > b
	// b + c > a
	// If at least one of the condition is not met for a triangle, the function must return false.
	virtual bool isValid() const = 0;

	// Return the string containing the shape info
	virtual std::string toString() const = 0;

	// Return the string containing shape properties
	virtual std::string getPropertyString() const = 0;

	// Return the name of the shape
	virtual ShapeType getShapeType() const = 0;

	// Return the pointer to the casted type.
	// The valid pointer is returned if the casted type is derived class, else a nullptr is returned
	// Note: The purpose of this function is to avoid using dynamic_cast (performance reason) in casting from base to derived class 
	template <class T>
	T* getPointer() {
		// Check if the object shape type is the same as the class shape type
		if (getShapeType() == T::getClassShapeType()) {
			return static_cast<T*>(this);
		}
		else {
			return nullptr;
		}
	}

protected:
	std::vector<double> getSerializedData(const std::vector<double>& input) const {
		std::vector<double> data(input);
		data.resize(getSerializationSize(), 0.);
	}
};