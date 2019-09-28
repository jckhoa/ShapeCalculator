#include "Donut.h"
#include <sstream>

Donut::Donut() : ci(0.), ce(0.) {}

Donut::Donut(double radius1, double radius2) {
	setSize(radius1, radius2);
}

Donut::~Donut() {}

void Donut::setSize(double radius1, double radius2) {
	// assign the radius values to internal and external circles
	// make sure that the internal circle radius is smaller than the external circle radius

	if (radius1 < radius2) {
		ci.setSize(radius1);
		ce.setSize(radius2);
	}
	else {
		ci.setSize(radius2);
		ce.setSize(radius1);
	}
}


// Return the number of double value used in serialized input
size_t Donut::getSerializationSize() const {
	return 2;
}

// Set input data from serialied double values
void Donut::setSize(const std::vector<double>& serializedInput) {
	std::vector<double> data = getSerializedData(serializedInput);
	setSize(data[0], data[1]);
}

double Donut::getInternalRadius() const {
	return ci.getRadius();
}

double Donut::getExternalRadius() const {
	return ce.getRadius();
}


ShapeType Donut::getClassShapeType() {
	return ShapeType::Donut;
}

ShapeType Donut::getShapeType() const {
	return ShapeType::Donut;
};

double Donut::getPerimeter() const {
	if (!isValid()) return 0.;
	return ci.getPerimeter() + ce.getPerimeter();
}

double Donut::getArea() const {
	if (!isValid()) return 0.;
	return ce.getArea() - ci.getArea();
}

bool Donut::isValid() const {
	return ci.isValid() && ce.isValid() && ci.getRadius() != ce.getRadius();
}

std::string Donut::toString() const {
	std::stringstream ss;
	ss << "Donut(intern_radius=" << ci.getRadius() << ",extern_radius=" << ce.getRadius() << ")";
	return ss.str();
}