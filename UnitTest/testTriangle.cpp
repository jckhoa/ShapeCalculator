#include "stdafx.h"
#include "CppUnitTest.h"
#include "Triangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestTriangle)
	{
	public:

		TEST_METHOD(TestConstructor0)
		{
			Triangle tri;
			Assert::AreEqual(0., tri.getFirstSide());
			Assert::AreEqual(0., tri.getSecondSide());
			Assert::AreEqual(0., tri.getThirdSide());
		}

		TEST_METHOD(TestConstructor1)
		{
			Triangle tri(2., 3., 4.);
			Assert::AreEqual(2., tri.getFirstSide());
			Assert::AreEqual(3., tri.getSecondSide());
			Assert::AreEqual(4., tri.getThirdSide());
		}

		TEST_METHOD(TestSetSize)
		{
			Triangle tri;
			tri.setSize(2., 3., 4.);
			Assert::AreEqual(2., tri.getFirstSide());
			Assert::AreEqual(3., tri.getSecondSide());
			Assert::AreEqual(4., tri.getThirdSide());
		}

		TEST_METHOD(TestGetFirstSide)
		{
			Triangle tri(2., 3., 4.);
			Assert::AreEqual(2., tri.getFirstSide());
		}

		TEST_METHOD(TestGetSecondSide)
		{
			Triangle tri(2., 3., 4.);
			Assert::AreEqual(3., tri.getSecondSide());
		}

		TEST_METHOD(TestGetThirdSide)
		{
			Triangle tri(2., 3., 4.);
			Assert::AreEqual(4., tri.getThirdSide());
		}

		TEST_METHOD(TestGetClassShapeType)
		{
			Assert::IsTrue(ShapeType::Triangle == Triangle::getClassShapeType());
		}

		TEST_METHOD(TestGetShapeType)
		{
			Triangle tri;
			Assert::IsTrue(ShapeType::Triangle == tri.getShapeType());
		}

		TEST_METHOD(TestGetPerimeter)
		{
			// Expect the perimeter to be zero if one of the side lengths is zero.
			Triangle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			Triangle z1(0., 3., 4.);
			Assert::AreEqual(0., z1.getPerimeter());
			Triangle z2(2., 0., 4.);
			Assert::AreEqual(0., z2.getPerimeter());
			Triangle z3(2., 3., 0.);
			Assert::AreEqual(0., z3.getPerimeter());

			// Expect the perimeter to be zero if one of the side lengths is negative.
			Triangle n1(-2., 3., 4.);
			Assert::AreEqual(0., n1.getPerimeter());
			Triangle n2(2., -3., 4.);
			Assert::AreEqual(0., n2.getPerimeter());
			Triangle n3(2., 3., -4.);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expected the perimeter to be zero if they do not satisfy the triangle condition
			Triangle c1(1., 2., 3.);
			Assert::AreEqual(0., c1.getPerimeter());
			Triangle c2(2., 3., 1.);
			Assert::AreEqual(0., c2.getPerimeter());
			Triangle c3(3., 1., 2.);
			Assert::AreEqual(0., c3.getPerimeter());
			Triangle c4(2., 4., 7.);
			Assert::AreEqual(0., c4.getPerimeter());
			Triangle c5(4., 7., 2.);
			Assert::AreEqual(0., c5.getPerimeter());
			Triangle c6(7., 2., 4.);
			Assert::AreEqual(0., c6.getPerimeter());

			// Expect the perimeter to be the sum of the sides for a valid triangle.
			Triangle tri(3., 4., 5.);
			double expected = 12.;
			Assert::AreEqual(expected, tri.getPerimeter());

		}

		TEST_METHOD(TestGetArea)
		{
			// Expect the area to be zero if one of the side lengths is zero.
			Triangle z0;
			Assert::AreEqual(0., z0.getArea());
			Triangle z1(0., 3., 4.);
			Assert::AreEqual(0., z1.getArea());
			Triangle z2(2., 0., 4.);
			Assert::AreEqual(0., z2.getArea());
			Triangle z3(2., 3., 0.);
			Assert::AreEqual(0., z3.getArea());

			// Expect the area to be zero if one of the side lengths is negative.
			Triangle n1(-2., 3., 4.);
			Assert::AreEqual(0., n1.getArea());
			Triangle n2(2., -3., 4.);
			Assert::AreEqual(0., n2.getArea());
			Triangle n3(2., 3., -4.);
			Assert::AreEqual(0., n3.getArea());

			// Expected the area to be zero if they do not satisfy the triangle condition
			Triangle c1(1., 2., 3.);
			Assert::AreEqual(0., c1.getArea());
			Triangle c2(2., 3., 1.);
			Assert::AreEqual(0., c2.getArea());
			Triangle c3(3., 1., 2.);
			Assert::AreEqual(0., c3.getArea());
			Triangle c4(2., 4., 7.);
			Assert::AreEqual(0., c4.getArea());
			Triangle c5(4., 7., 2.);
			Assert::AreEqual(0., c5.getArea());
			Triangle c6(7., 2., 4.);
			Assert::AreEqual(0., c6.getArea());

			// Expect positive area for a valid triangle.
			Triangle tri(3., 4., 5.);
			double expected = 6.;
			Assert::AreEqual(expected, tri.getArea());

		}

		TEST_METHOD(TestIsValid)
		{
			// Expect the area to be zero if one of the side lengths is zero.
			Triangle z0;
			Assert::IsFalse(z0.isValid());
			Triangle z1(0., 3., 4.);
			Assert::IsFalse(z1.isValid());
			Triangle z2(2., 0., 4.);
			Assert::IsFalse(z2.isValid());
			Triangle z3(2., 3., 0.);
			Assert::IsFalse(z3.isValid());

			// Expect the area to be zero if one of the side lengths is negative.
			Triangle n1(-2., 3., 4.);
			Assert::IsFalse(n1.isValid());
			Triangle n2(2., -3., 4.);
			Assert::IsFalse(n2.isValid());
			Triangle n3(2., 3., -4.);
			Assert::IsFalse(n3.isValid());

			// Expected the area to be zero if they do not satisfy the triangle condition
			Triangle c1(1., 2., 3.);
			Assert::IsFalse(c1.isValid());
			Triangle c2(2., 3., 1.);
			Assert::IsFalse(c2.isValid());
			Triangle c3(3., 1., 2.);
			Assert::IsFalse(c3.isValid());
			Triangle c4(2., 4., 7.);
			Assert::IsFalse(c4.isValid());
			Triangle c5(4., 7., 2.);
			Assert::IsFalse(c5.isValid());
			Triangle c6(7., 2., 4.);
			Assert::IsFalse(c6.isValid());

			// Expect positive area for a valid triangle.
			Triangle tri(3., 4., 5.);
			Assert::IsTrue(tri.isValid());

		}
	};
}