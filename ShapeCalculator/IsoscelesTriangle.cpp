#include "IsoscelesTriangle.h"

IsoscelesTriangle::IsoscelesTriangle() : side(0.), base(0.) {

}

IsoscelesTriangle::IsoscelesTriangle(double side, double base) : side(side), base(base) {

}

void IsoscelesTriangle::setSize(double side, double base) {
	this->side = side;
	this->base = base;
}

double IsoscelesTriangle::getSide() {
	return side;
}

double IsoscelesTriangle::getBase() {
	return base;
}

ShapeType IsoscelesTriangle::getClassShapeType() {
	return ShapeType::IsoscelesTriangle;
}

ShapeType IsoscelesTriangle::getShapeType() {
	return ShapeType::IsoscelesTriangle;
};

double IsoscelesTriangle::getPerimeter() {
	return side * 2 + base;
}

double IsoscelesTriangle::getArea() {
	// if the isosceles triangle is not valid, return 0.
	if (!isValid()) return 0.;

	// compute height from Pythagore theorem
	double halfBase = base / 2;
	double height = sqrt(side * side - halfBase * halfBase);

	return halfBase * height;
}

bool IsoscelesTriangle::isValid() {
	return (side + side > base) && side > 0 && base > 0;
}
