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
	c.setRadius(5.);
	std::cout << "Circle radius after change: " << c.getRadius() << std::endl;
	std::cout << "Circle is valid? " << c.isValid() << std::endl;
	std::cout << "Circle is valid (through base)? " << ((Shape*)&c)->isValid() << std::endl;
	std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
	std::cout << "Circle area: " << c.getArea() << std::endl;
	std::cout << "Shape name: " << c.getShapeName() << std::endl;
	std::cout << "Shape name through base: " << ((Shape*)&c)->getShapeName() << std::endl;
	
	std::cout << std::endl;
	c.setRadius(0.);
	std::cout << "Circle radius after change: " << c.getRadius() << std::endl;
	std::cout << "Circle is valid? " << c.isValid() << std::endl;
	std::cout << "Circle is valid (through base)? " << ((Shape*)&c)->isValid() << std::endl;
	std::cout << "Circle perimeter: " << c.getPerimeter() << std::endl;
	std::cout << "Circle area: " << c.getArea() << std::endl;
	
	std::cout << std::endl;
	c.setRadius(-2.5);
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
	Circle* cc = *s;
	std::cout << "Shape to Circle Downcast address: " << cc << std::endl;
	Donut* dd = *s;
	std::cout << "Shape to Donut Downcast address: " << dd << std::endl;


	//Test conversion by reference
	std::cout << std::endl << "Test conversion by reference" << std::endl;
	Shape& ss = c;
	Circle& ccc = ss;
	
	std::cout << "Circle radius: " << ccc.getRadius() << std::endl;
	Donut& ddd = ss;
	std::cout << "Donut area: " << ddd.getArea() << std::endl;

	return 0;
}