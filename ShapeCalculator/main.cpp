#include "Circle.h"

#include <iostream>
#include "Donut.h"

int main(void) {

	std::cout << "Test empty constructor. Expect the radius to be 0." << std::endl;
	Circle c;
	std::cout << std::endl;
	std::cout << "Circle radius: " << c.getRadius() << std::endl;
	
	std::cout << "Test changing radius parameter";
	std::cout << std::endl;
	c.setSize(5.);
	std::cout << "Circle radius after change: " << c.getRadius() << std::endl;
	std::cout << "Circle is valid? " << c.isValid() << std::endl;
	std::cout << "Circle is valid (through base)? " << ((Shape*)&c)->isValid() << std::endl;
	std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
	std::cout << "Circle area: " << c.getArea() << std::endl;
	std::cout << "Shape type: " << (c.getShapeType() == ShapeType::Circle) << std::endl;
	std::cout << "Shape name through base: " << (((Shape*)&c)->getShapeType() == ShapeType::Circle) << std::endl;
	
	std::cout << std::endl;
	c.setSize(0.);
	std::cout << "Circle radius after change: " << c.getRadius() << std::endl;
	std::cout << "Circle is valid? " << c.isValid() << std::endl;
	std::cout << "Circle is valid (through base)? " << ((Shape*)&c)->isValid() << std::endl;
	std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
	std::cout << "Circle area: " << c.getArea() << std::endl;
	
	std::cout << std::endl;
	c.setSize(-2.5);
	std::cout << "Circle radius after change: " << c.getRadius() << std::endl;
	std::cout << "Circle is valid? " << c.isValid() << std::endl;
	std::cout << "Circle is valid (through base)? " << ((Shape*)&c)->isValid() << std::endl;
	std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
	std::cout << "Circle area: " << c.getArea() << std::endl;

	//Test conversion by pointer
	std::cout << std::endl << "Test conversion by pointer" << std::endl;
	Shape* s = &c;
	std::cout << "Circle address: " << &c << std::endl;
	std::cout << "Shape address: " << s << std::endl;;
	Circle* cc = s->getPointer<Circle>();
	std::cout << "Shape to Circle Downcast address: " << cc << std::endl;
	Donut* dd = s->getPointer<Donut>();
	std::cout << "Shape to Donut Downcast address: " << dd << std::endl;

	return 0;
}