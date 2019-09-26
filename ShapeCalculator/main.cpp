#include "Circle.h"

#include <iostream>
#include <vector>

#include "Circle.h"
#include "Donut.h"
#include "Triangle.h"
#include "IsoscelesTriangle.h"
#include "RectangularTriangle.h"
#include "Square.h"
#include "Rectangle.h"

int main(void) {
	// some Circle usage
	std::cout << "------- Example on some Circle usage ------" << std::endl;
	{
		// Create a circle with radius equal to 0.
		Circle c1;
		Circle c2(0.);

		// Create a circle with radius of 5 or -5.
		Circle c3(5.);
		Circle c4(-5.);

		// Get object shape type
		ShapeType objectShapeType = c1.getShapeType(); // should return ShapeType::Circle

		// Get class shape type
		ShapeType classShapeType = c1.getClassShapeType(); // should return ShapeType::Circle

		// Show a circle information
		std::cout << "Info of c1: " << c1.toString() << std::endl;
		std::cout << "Info of c2: " << c2.toString() << std::endl;
		std::cout << "Info of c3: " << c3.toString() << std::endl;
		std::cout << "Info of c4: " << c4.toString() << std::endl;

		// Get and show the radii of the circles in the console
		std::cout << "Radius of c1: " << c1.getRadius() << std::endl;
		std::cout << "Radius of c2: " << c2.getRadius() << std::endl;
		std::cout << "Radius of c3: " << c3.getRadius() << std::endl;
		std::cout << "Radius of c4: " << c4.getRadius() << std::endl;

		// Get and show if the circles are valid in the console
		std::cout << "c1 is valid ? " << (c1.isValid() ? "yes" : "no") << std::endl;
		std::cout << "c2 is valid ? " << (c2.isValid() ? "yes" : "no") << std::endl;
		std::cout << "c3 is valid ? " << (c3.isValid() ? "yes" : "no") << std::endl;
		std::cout << "c4 is valid ? " << (c4.isValid() ? "yes" : "no") << std::endl;

		// Get and show the the perimeter of the circles
		std::cout << "c1 has perimeter: " << c1.getPerimeter() << std::endl; // the perimeter is 0 because the circle is invalid
		std::cout << "c2 has perimeter: " << c2.getPerimeter() << std::endl; // the perimeter is 0 because the circle is invalid
		std::cout << "c3 has perimeter: " << c3.getPerimeter() << std::endl; // the perimeter is a positive value
		std::cout << "c4 has perimeter: " << c4.getPerimeter() << std::endl; // the perimeter is 0 because the circle is invalid
	}

	// Some Triangle usage
	std::cout << "------- Example on some Triangle usage ------" << std::endl;
	{
		// create a triangle
		Triangle tri1(2., 3., 5.);
		Triangle tri2(5., 2., 2.);
		Triangle tri3(3., 4., 5.);

		// get and show if the triangles are valid
		std::cout << tri1.toString() << " is valid ? " << (tri1.isValid() ? "yes." : "no.") << " Because the sum of the first two sides is not greater than the third side" << std::endl;
		std::cout << tri2.toString() << " is valid ? " << (tri2.isValid() ? "yes." : "no.") << " Because the sum of the last two sides is not greater than the third side" << std::endl;
		std::cout << tri3.toString() << " is valid ? " << (tri3.isValid() ? "yes." : "no.") << " Because the sum of any two sides is greater than the third side" << std::endl;

		// get and show the triangle perimeters and areas
		// An invalid triangle always return zero perimeter and zero area.
		std::cout << tri1.toString() << " has perimeter of " << tri1.getPerimeter() << " and area of " << tri1.getArea() << std::endl;
		std::cout << tri2.toString() << " has perimeter of " << tri2.getPerimeter() << " and area of " << tri2.getArea() << std::endl;
		std::cout << tri3.toString() << " has perimeter of " << tri3.getPerimeter() << " and area of " << tri3.getArea() << std::endl;

	}

	// Casting forward and backward between Base and Derived classes: Example 1
	std::cout << "------- Example on Base <-> Derived casting: example 1 ------" << std::endl;
	{
		Rectangle rec(5, 6); // Create a rectangle

		RectangleShape* recShape = &rec; // cast to base class
		std::cout << "Perimeter of rec is " << rec.getPerimeter() << std::endl;
		std::cout << "Perimeter of recShape is " << recShape->getPerimeter() << std::endl;
		
		// cast from Base to Rectangle object (true derived object of RectangleShape), should return a valid pointer
		Rectangle* recPointer = recShape->getPointer<Rectangle>(); 
		std::cout << "recPointer is not null ? " << (recPointer != nullptr ? "yes" : "no") << std::endl;

		// cast from Base to Square object (not a true derived object of RectangleShape), should return a null pointer
		Square* squarePointer = recShape->getPointer<Square>(); 
		std::cout << "squarePointer is null ? " << (squarePointer == nullptr ? "yes" : "no") << std::endl;
	}

	
	// Casting forward and backward between Base and Derived classes: Example 2
	std::cout << "------- Example on Base <-> Derived casting: example 2 ------" << std::endl;
	{
		Square* sq = new Square(4); // Create a square
		Shape2D* sqShape = sq;
		std::cout << "Area of sq is " << sq->getArea() << std::endl;
		std::cout << "Area of sqShape is " << sqShape->getArea() << std::endl;
		delete sq;
		std::cout << std::endl;
	}

	// Array of mixed shapes: Example 1
	std::cout << "------- Example on array of mixed shapes: example 1 ------" << std::endl;
	{
		TriangleShape* triangles[3] = { new Triangle(3., 4., 5.), new IsoscelesTriangle(5, 6), new RectangularTriangle(8, 10) };
		std::cout << "The perimeters of the triangles are: " << std::endl;
		for (int i = 0; i < 3; ++i) {
			std::cout << triangles[i]->toString() << " has perimeter of " << triangles[i]->getPerimeter() << std::endl;
		}
		for (int i = 0; i < 3; ++i) {
			delete triangles[i];
		}

	}

	// Array of mixed shapes: Example 2
	std::cout << "------- Example on array of mixed shapes: example 2 ------" << std::endl;
	{
		std::vector<Shape*> shapes;
		shapes.push_back(new Triangle(3., 4., 5.));
		shapes.push_back(new Rectangle(0., 7.));
		shapes.push_back(new Donut(-3, 4));

		for (const auto& shape : shapes) {
			std::cout << shape->toString() << " is valid ? " << (shape->isValid() ? "yes. " : "no. ") << std::endl;
		}

		for (auto& shape : shapes) delete shape;
	}
	return 0;
}