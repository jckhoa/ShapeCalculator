#include "stdafx.h"
#include "CppUnitTest.h"
#include "RectangularTriangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestRectangularTriangle)
	{
	public:

		//Test empty constructor
		TEST_METHOD(TestRectangularTriangle_Constructor0)
		{
			RectangularTriangle rec;
			Assert::AreEqual(0., rec.getFirstSide());
			Assert::AreEqual(0., rec.getSecondSide());
		}

		//Test constructor with 2 arguments
		TEST_METHOD(TestRectangularTriangle_Constructor2)
		{
			RectangularTriangle rec(2., 3.);
			Assert::AreEqual(2., rec.getFirstSide());
			Assert::AreEqual(3., rec.getSecondSide());
		}

		TEST_METHOD(TestRectangularTriangle_SetSize)
		{
			RectangularTriangle rec;
			rec.setSize(2., 3.);
			Assert::AreEqual(2., rec.getFirstSide());
			Assert::AreEqual(3., rec.getSecondSide());
		}

		TEST_METHOD(TestRectangularTriangle_GetFirstSide)
		{
			RectangularTriangle rec(2., 3.);
			Assert::AreEqual(2., rec.getFirstSide());
		}

		TEST_METHOD(TestRectangularTriangle_GetSecondSide)
		{
			RectangularTriangle rec(2., 3.);
			Assert::AreEqual(3., rec.getSecondSide());
		}

		TEST_METHOD(TestRectangularTriangle_GetClassShapeType)
		{
			Assert::IsTrue(ShapeType::RectangularTriangle == RectangularTriangle::getClassShapeType());
		}

		TEST_METHOD(TestRectangularTriangle_GetShapeType)
		{
			RectangularTriangle rec;
			Assert::IsTrue(ShapeType::RectangularTriangle == rec.getShapeType());
		}

		TEST_METHOD(TestRectangularTriangle_GetPerimeter)
		{
			// Expect the perimeter to be zero if one of the side lengths is zero.
			RectangularTriangle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			RectangularTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getPerimeter());
			RectangularTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getPerimeter());

			// Expect the perimeter to be zero if one of the side lengths is negative.
			RectangularTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getPerimeter());
			RectangularTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getPerimeter());
			RectangularTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expect positive perimeter for positive side lengths
			RectangularTriangle rec(3., 4.);
			double expected = 12.;
			Assert::AreEqual(expected, rec.getPerimeter());

		}

		TEST_METHOD(TestRectangularTriangle_GetArea)
		{
			// Expect the area to be zero if one of the side lengths is zero.
			RectangularTriangle z0;
			Assert::AreEqual(0., z0.getArea());
			RectangularTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getArea());
			RectangularTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getArea());

			// Expect the area to be zero if one of the side lengths is negative.
			RectangularTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getArea());
			RectangularTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getArea());
			RectangularTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getArea());

			// Expect positive area for positive side lengths
			RectangularTriangle rec(3., 4.);
			double expected = 6.;
			Assert::AreEqual(expected, rec.getArea());

		}

		TEST_METHOD(TestRectangularTriangle_IsValid)
		{
			// Expect false if one of the side lengths is zero.
			RectangularTriangle z0;
			Assert::IsFalse(z0.isValid());
			RectangularTriangle z1(0., 2.);
			Assert::IsFalse(z1.isValid());
			RectangularTriangle z2(2., 0.);
			Assert::IsFalse(z2.isValid());

			// Expect false if one of the side lengths is negative.
			RectangularTriangle n1(-4.2, 3);
			Assert::IsFalse(n1.isValid());
			RectangularTriangle n2(4.2, -3);
			Assert::IsFalse(n2.isValid());
			RectangularTriangle n3(-4.2, -3);
			Assert::IsFalse(n3.isValid());

			// Expect true for positive side lengths
			RectangularTriangle rec(3., 4.);
			Assert::IsTrue(rec.isValid());

		}

		TEST_METHOD(TestRectangularTriangle_ToString) {
			double side1 = 5;
			double side2 = 6;
			RectangularTriangle tri(side1, side2);
			std::string expected("RectangularTriangle(side1=5,side2=6)");
			Assert::AreEqual(expected, tri.toString());
		}
	};
}