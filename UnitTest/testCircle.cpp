#include "stdafx.h"
#include "CppUnitTest.h"
#include "Circle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{		
	TEST_CLASS(UnitTestCircle)
	{
	public:
		
		//Test empty constructor
		TEST_METHOD(TestCircle_Constructor0)
		{
			Circle c;
			Assert::AreEqual(0., c.getRadius());
		}

		//Test constructor with 1 argument
		TEST_METHOD(TestCircle_Constructor1)
		{
			Circle c(2.);
			Assert::AreEqual(2., c.getRadius());
		}

		TEST_METHOD(TestCircle_SetSize)
		{
			Circle c(2.);
			c.setSize(2.5);
			Assert::AreEqual(2.5, c.getRadius());
		}

		TEST_METHOD(TestCircle_GetRadius)
		{
			Circle c(7.3234);
			Assert::AreEqual(7.3234, c.getRadius());
		}

		TEST_METHOD(TestCircle_GetClassShapeType)
		{
			Assert::IsTrue(ShapeType::Circle == Circle::getClassShapeType());
		}

		TEST_METHOD(TestCircle_GetShapeType)
		{
			Circle c;
			Assert::IsTrue(ShapeType::Circle == c.getShapeType());
		}

		TEST_METHOD(TestCircle_GetPerimeter)
		{
			// Expect the perimeter to be zero for zero radius
			Circle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			Circle z1(0.);
			Assert::AreEqual(0., z1.getPerimeter());

			// Expect the perimeter to be zero for negative radius
			Circle c1(-4.2);
			Assert::AreEqual(0., c1.getPerimeter());
			
			// Expect the perimeter to be 2 * pi * r for positive radius r
			double r = 3.5;
			Circle c2(r);
			Assert::AreEqual(r * M_PI * 2, c2.getPerimeter());

		}

		TEST_METHOD(TestCircle_GetArea)
		{
			// Expect the area to be zero for zero radius
			Circle z0;
			Assert::AreEqual(0., z0.getArea());
			Circle z1(0.);
			Assert::AreEqual(0., z1.getArea());

			// Expect the area to be zero for negative radius
			Circle c1(-4.2);
			Assert::AreEqual(0., c1.getArea());

			// Expect the perimeter to be pi * r * r for positive radius r
			double r = 3.5;
			Circle c2(r);
			Assert::AreEqual(M_PI * r * r, c2.getArea());

		}

		TEST_METHOD(TestCircle_IsValid)
		{
			// Expect false for zero radius
			Circle z0;
			Assert::IsFalse(z0.isValid());
			Circle z1(0.);
			Assert::IsFalse(z1.isValid());

			// Expect false for negative radius
			Circle c1(-4.2);
			Assert::IsFalse(c1.isValid());

			// Expect true for positive radius r
			double r = 3.5;
			Circle c2(r);
			Assert::IsTrue(c2.isValid());

		}

		TEST_METHOD(TestCircle_ToString) {
			double radius = 5.5;
			Circle c(radius);
			std::string expected("Circle(radius=5.5)");
			Assert::AreEqual(expected, c.toString());
		}
	};
}