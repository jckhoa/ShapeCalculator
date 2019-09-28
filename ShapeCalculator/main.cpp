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

#include "ArgumentParser.h"

int main(int argc, char *argv[]) {

	// Create an argument parser
	ArgumentParser parser;

	// Add command line option for each shape
	parser.addOption<Circle>("c", "radius", "Compute perimeter and area of a Circle");
	parser.addOption<Donut>("d", "internalRadius externalRadius", "Compute perimeter and area of a Donut");
	parser.addOption<Rectangle>("r", "width height", "Compute perimeter and area of a Rectangle");
	parser.addOption<Square>("s", "side", "Compute perimeter and area of a Square");
	parser.addOption<Triangle>("t", "side1 side2 side3", "Compute perimeter and area of a Triangle");
	parser.addOption<IsoscelesTriangle>("it", "side base", "Compute perimeter and area of a IsoscelesTriangle");
	parser.addOption<RectangularTriangle>("rt", "side1 side2", "Compute perimeter and area of a RectanglarTriangle");

	std::string errorMessage;

	// Process the command line and print out results or errors if any in the console
	if (parser.process(argc, argv, errorMessage)) {
		std::cout << parser.getResults() << std::endl;
	}
	else {
		std::cout << errorMessage << std::endl;
		std::cout << std::endl << parser.getHelpMessage() << std::endl;
	}

	return 0;

	/*
	// some Circle usage
	std::cout << std::endl << "------- Example on some Circle usage ------" << std::endl;
	{
		// Create a circle with radius equal to 0.
		Circle c1;
		Circle c2(0.);

		// Create a circle with radius of 5 or -5.
		Circle c3(5.);
		Circle c4(-5.);

		// Get object shape name
		std::string objectstd::string = c1.getShapeName(); // should return std::string::Circle

		// Get class shape name
		std::string classstd::string = c1.getClassShapeName(); // should return std::string::Circle

		// Show a circle information
		std::cout << "Info of c1: " << c1.getInfoString() << std::endl;
		std::cout << "Info of c2: " << c2.getInfoString() << std::endl;
		std::cout << "Info of c3: " << c3.getInfoString() << std::endl;
		std::cout << "Info of c4: " << c4.getInfoString() << std::endl;

		// Get and show the radii of the circles in the console
		std::cout << "Radius of c1: " << c1.getRadius() << std::endl;
		std::cout << "Radius of c2: " << c2.getRadius() << std::endl;
		std::cout << "Radius of c3: " << c3.getRadius() << std::endl;
		std::cout << "Radius of c4: " << c4.getRadius() << std::endl;

		// Get and show if the circles are valid in the console
		std::cout << "c1 is " << (c1.isValid() ? "valid" : "invalid") << ", because its radius is 0." << std::endl;
		std::cout << "c2 is " << (c2.isValid() ? "valid" : "invalid") << ", because its radius is 0." << std::endl;
		std::cout << "c3 is " << (c3.isValid() ? "valid" : "invalid") << ", because its radius is positive" << std::endl;
		std::cout << "c4 is " << (c4.isValid() ? "valid" : "invalid") << ", because its radius is nagative" << std::endl;

		// Get and show the the perimeter of the circles
		// Invalid circles always return zero perimeter and area.
		std::cout << "c1 has perimeter: " << c1.getPerimeter() << std::endl; // the perimeter is 0 because the circle is invalid
		std::cout << "c2 has perimeter: " << c2.getPerimeter() << std::endl; // the perimeter is 0 because the circle is invalid
		std::cout << "c3 has perimeter: " << c3.getPerimeter() << std::endl; // the perimeter is a positive value
		std::cout << "c4 has perimeter: " << c4.getPerimeter() << std::endl; // the perimeter is 0 because the circle is invalid
	}

	// Some Triangle usage
	std::cout << std::endl << "------- Example on some Triangle usage ------" << std::endl;
	{
		// create a triangle
		Triangle tri1(2., 3., 5.);
		Triangle tri2(5., 2., 2.);
		Triangle tri3(3., 4., 5.);

		// get and show if the triangles are valid
		std::cout << tri1.getInfoString() << " is " << (tri1.isValid() ? "valid" : "invalid") << ", because the sum of the first two sides is not greater than the third side" << std::endl;
		std::cout << tri2.getInfoString() << " is " << (tri2.isValid() ? "valid" : "invalid") << ", because the sum of the last two sides is not greater than the third side" << std::endl;
		std::cout << tri3.getInfoString() << " is " << (tri3.isValid() ? "valid" : "invalid") << ", because the sum of any two sides is greater than the third side" << std::endl;

		// get and show the triangle perimeters and areas
		// An invalid triangle always return zero perimeter and zero area.
		std::cout << tri1.getInfoString() << " has perimeter of " << tri1.getPerimeter() << " and area of " << tri1.getArea() << std::endl;
		std::cout << tri2.getInfoString() << " has perimeter of " << tri2.getPerimeter() << " and area of " << tri2.getArea() << std::endl;
		std::cout << tri3.getInfoString() << " has perimeter of " << tri3.getPerimeter() << " and area of " << tri3.getArea() << std::endl;

	}

	// Casting forward and backward between Base and Derived classes: Example 1
	std::cout << std::endl << "------- Example on Base <-> Derived casting: example 1 ------" << std::endl;
	{
		Rectangle rec(5, 6); // Create a rectangle

		RectangleShape* recShape = &rec; // cast from derived to base object
		std::cout << "Perform casting from rec (type:Rectangle) to recShape (type:RectangleShape*)" << std::endl;
		std::cout << "Perimeter of rec (type=Rectangle) is " << rec.getPerimeter() << std::endl;
		std::cout << "Perimeter of recShape (type=RectangleShape) is " << recShape->getPerimeter() << std::endl;
		
		// cast from Base to Rectangle object (true derived object of RectangleShape), should return a valid pointer
		Rectangle* recPointer = recShape->getPointer<Rectangle>(); 
		std::cout << "Perform casting from recShape (type:RectangleShape*) to recPointer (type:Rectangle*). recShape is a true base object of a Rectangle" << std::endl;
		std::cout << "recPointer (type=Rectangle*) is " << (recPointer == nullptr ? "null" : "not null") << std::endl;

		// cast from Base to Square object (not a true derived object of RectangleShape), should return a null pointer
		Square* squarePointer = recShape->getPointer<Square>(); 
		std::cout << "Perform casting from recShape (type:RectangleShape*) to squarePointer (type:Square*). recShape is a not true base object of a Square" << std::endl;
		std::cout << "squarePointer (type=Square*) is " << (squarePointer == nullptr ? "null" : "not null") << std::endl;
	}

	
	// Casting forward and backward between Base and Derived classes: Example 2
	std::cout << std::endl << "------- Example on Base <-> Derived casting: example 2 ------" << std::endl;
	{
		Square* sq = new Square(4); // Create a square
		Shape2D* sqShape = sq;
		std::cout << "Perform casting from sq (Square*) to sqShape (Shape2D*)" << std::endl;
		std::cout << "Area of sq (type=Square*) is " << sq->getArea() << std::endl;
		std::cout << "Area of sqShape (type=Shape2D*) is " << sqShape->getArea() << std::endl;
		delete sq;
		std::cout << std::endl;
	}

	// Array of mixed shapes: Example 1
	std::cout << std::endl << "------- Example on array of mixed shapes: example 1 ------" << std::endl;
	{
		TriangleShape* triangles[3] = { new Triangle(3., 4., 5.), new IsoscelesTriangle(5, 6), new RectangularTriangle(8, 10) };
		std::cout << "The perimeters of the triangles are: " << std::endl;
		for (int i = 0; i < 3; ++i) {
			std::cout << triangles[i]->getInfoString() << " has perimeter of " << triangles[i]->getPerimeter() << std::endl;
		}
		for (int i = 0; i < 3; ++i) {
			delete triangles[i];
		}

	}

	// Array of mixed shapes: Example 2
	std::cout << std::endl << "------- Example on array of mixed shapes: example 2 ------" << std::endl;
	{
		std::vector<Shape2D*> shapes;
		shapes.push_back(new Triangle(3., 4., 5.));
		shapes.push_back(new Rectangle(0., 7.));
		shapes.push_back(new Donut(-3, 4));

		std::cout << "Validity of the 2D shapes: " << std::endl;
		for (const auto& shape : shapes) {
			std::cout << shape->getInfoString() << " is " << (shape->isValid() ? "valid" : "invalid") << std::endl;
		}

		for (auto& shape : shapes) delete shape;
	}
	*/


}