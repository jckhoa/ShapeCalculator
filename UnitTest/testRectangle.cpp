#include "stdafx.h"
#include "CppUnitTest.h"
#include "Rectangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestRectangle)
	{
	public:

		TEST_METHOD(TestConstructor0)
		{
			Rectangle rec;
			Assert::AreEqual(0., rec.getWidth());
			Assert::AreEqual(0., rec.getHeight());
		}

		TEST_METHOD(TestConstructor1)
		{
			Rectangle rec(2., 3.);
			Assert::AreEqual(2., rec.getWidth());
			Assert::AreEqual(3., rec.getHeight());
		}

		TEST_METHOD(TestSetSize)
		{
			Rectangle rec;
			rec.setSize(2., 3.);
			Assert::AreEqual(2., rec.getWidth());
			Assert::AreEqual(3., rec.getHeight());
		}

		TEST_METHOD(TestGetWidth)
		{
			Rectangle rec(2., 3.);
			Assert::AreEqual(2., rec.getWidth());
		}

		TEST_METHOD(TestGetHeight)
		{
			Rectangle rec(2., 3.);
			Assert::AreEqual(3., rec.getHeight());
		}

		TEST_METHOD(TestIsSquare)
		{
			// expect false when the width is not equal to height
			Rectangle rec1(2., 3.);
			Assert::IsFalse(rec1.isSquare());

			// expect true when the width is equal to height
			Rectangle rec2(2., 2.);
			Assert::IsTrue(rec2.isSquare());
		}

		TEST_METHOD(TestGetClassShapeType)
		{
			Assert::IsTrue(ShapeType::Rectangle == Rectangle::getClassShapeType());
		}

		TEST_METHOD(TestGetShapeType)
		{
			Rectangle rec;
			Assert::IsTrue(ShapeType::Rectangle == rec.getShapeType());
		}

		TEST_METHOD(TestGetPerimeter)
		{
			// Expect the perimeter to be zero for zero width or zero height
			Rectangle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			Rectangle z1(0., 2.);
			Assert::AreEqual(0., z1.getPerimeter());
			Rectangle z2(2., 0.);
			Assert::AreEqual(0., z2.getPerimeter());

			// Expect the perimeter to be zero for negative width or negative height
			Rectangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getPerimeter());
			Rectangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getPerimeter());
			Rectangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expect the perimeter to be 2 * (width + height) for positive width and height
			Rectangle rec(2., 3.);
			double expected = 10.;
			Assert::AreEqual(expected, rec.getPerimeter());

		}

		TEST_METHOD(TestGetArea)
		{
			// Expect the area to be zero for zero width or zero height
			Rectangle z0;
			Assert::AreEqual(0., z0.getArea());
			Rectangle z1(0., 2.);
			Assert::AreEqual(0., z1.getArea());
			Rectangle z2(2., 0.);
			Assert::AreEqual(0., z2.getArea());

			// Expect the area to be zero for negative width or negative height
			Rectangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getArea());
			Rectangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getArea());
			Rectangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getArea());

			// Expect the area to be width * height for positive width and height
			Rectangle rec(2., 3.);
			double expected = 6.;
			Assert::AreEqual(expected, rec.getArea());

		}

		TEST_METHOD(TestIsValid)
		{
			// Expect false for zero width or zero height
			Rectangle z0;
			Assert::IsFalse(z0.isValid());
			Rectangle z1(0., 2.);
			Assert::IsFalse(z1.isValid());
			Rectangle z2(2., 0.);
			Assert::IsFalse(z2.isValid());

			// Expect false for negative width or negative height
			Rectangle n1(-4.2, 3);
			Assert::IsFalse(n1.isValid());
			Rectangle n2(4.2, -3);
			Assert::IsFalse(n2.isValid());
			Rectangle n3(-4.2, -3);
			Assert::IsFalse(n3.isValid());

			// Expect true for positive width and height
			Rectangle rec(2., 3.);
			Assert::IsTrue(rec.isValid());

		}
	};
}