#include "Donut.h"

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

double Donut::getInternalRadius() {
	return ci.getRadius();
}

double Donut::getExternalRadius() {
	return ce.getRadius();
}


ShapeType Donut::getClassShapeType() {
	return ShapeType::Donut;
}

ShapeType Donut::getShapeType() {
	return ShapeType::Donut;
};

double Donut::getPerimeter() {
	if (!isValid()) return 0.;
	return ci.getPerimeter() + ce.getPerimeter();
}

double Donut::getArea() {
	if (!isValid()) return 0.;
	return ce.getArea() - ci.getArea();
}

bool Donut::isValid() {
	return ci.isValid() && ce.isValid() && ci.getRadius() != ce.getRadius();
}
