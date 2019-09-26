#include "Circle.h"

#include <iostream>

#include "Circle.h"
#include "Triangle.h"

int main(void) {
	// Circle usage
	{
		// Create a circle with radius equal to 0.
		Circle c1;
		Circle c2(0.);

		// Create a circle with radius of 5 or -5.
		Circle c3(5.);
		Circle c4(-5.);

		// Get the radii from the circles
		double radius1 = c1.getRadius(); // return 0
		double radius2 = c2.getRadius(); // return 0
		double radius3 = c3.getRadius(); // return 5
		double radius4 = c4.getRadius(); // return -5

		// Show radii of the circles on the screen
		std::cout << "Radius of c1: " << radius1 << std::endl;
		std::cout << "Radius of c2: " << radius2 << std::endl;
		std::cout << "Radius of c3: " << radius3 << std::endl;
		std::cout << "Radius of c4: " << radius4 << std::endl;

		// Show if the circles are valid
		bool isValid1 = c1.isValid(); // return false because the radius is 0
		bool isValid2 = c2.isValid(); // return false because the radius is 0
		bool isValid3 = c3.isValid(); // return true because the radius is positive
		bool isValid4 = c4.isValid(); // return false because the radius is negative

		std::cout << "c1 is valid ? " << (isValid1 ? "yes" : "no") << std::endl;
		std::cout << "c2 is valid ? " << (isValid2 ? "yes" : "no") << std::endl;
		std::cout << "c3 is valid ? " << (isValid3 ? "yes" : "no") << std::endl;
		std::cout << "c4 is valid ? " << (isValid4 ? "yes" : "no") << std::endl;

		// Get the perimeter of the circles
		double perimeter1 = c1.getPerimeter(); // return 0 because the circle is not valid
		double perimeter2 = c2.getPerimeter(); // return 0 because the circle is not valid
		double perimeter3 = c3.getPerimeter(); // return a positive value
		double perimeter4 = c4.getPerimeter(); // return 0 because the circle is not valid
	}

	// Triangle usage
	{
		// create a triangle
		Triangle tri1(2., 3., 5.);
		Triangle tri2(5., 2., 2.);
		Triangle tri3(3., 4., 5.);

		bool isValid1 = tri1.isValid(); // return false because the sum of the first two sides is not greater than the third.
		bool isValid2 = tri2.isValid(); // return false because the sum of the last two sides is not greater than the third.
		bool isValid3 = tri3.isValid(); // return true because the sum of any two sides is greater than the third one.

		std::cout << "tri1 is valid ? " << (isValid1 ? "yes" : "no") << std::endl;
		std::cout << "tri2 is valid ? " << (isValid2 ? "yes" : "no") << std::endl;
		std::cout << "tri3 is valid ? " << (isValid3 ? "yes" : "no") << std::endl;

	}
	return 0;
}