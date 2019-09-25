#include "stdafx.h"
#include "CppUnitTest.h"
#include "Donut.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestDonut)
	{
	public:

		TEST_METHOD(TestConstructor0)
		{
			
			Donut d;
			Assert::AreEqual(0., d.getInternalRadius());
			Assert::AreEqual(0., d.getExternalRadius());
		}

		TEST_METHOD(TestConstructor1)
		{
			Donut d1(2., 3.);
			Assert::AreEqual(2., d1.getInternalRadius());
			Assert::AreEqual(3., d1.getExternalRadius());

			// Check if the internal and external radius are still correct after switching their order in the constructor
			Donut d2(3., 2.);
			Assert::AreEqual(2., d1.getInternalRadius());
			Assert::AreEqual(3., d1.getExternalRadius());

		}

		TEST_METHOD(TestSetSize)
		{
			Donut d;
			d.setSize(2., 3.);
			Assert::AreEqual(2., d.getInternalRadius());
			Assert::AreEqual(3., d.getExternalRadius());

			// Check if the internal and external radius are still correct after switching their order in the constructor
			d.setSize(3., 2.);
			Assert::AreEqual(2., d.getInternalRadius());
			Assert::AreEqual(3., d.getExternalRadius());

		}

		TEST_METHOD(TestGetInternalRadius)
		{
			Donut d1(4., 5.);
			Assert::AreEqual(4., d1.getInternalRadius());

			Donut d2(5., 4.);
			Assert::AreEqual(4., d2.getInternalRadius());
		}

		TEST_METHOD(TestGetExternalRadius)
		{
			Donut d1(4., 5.);
			Assert::AreEqual(5., d1.getExternalRadius());

			Donut d2(5., 4.);
			Assert::AreEqual(5., d2.getExternalRadius());
		}

		TEST_METHOD(TestGetClassShapeType)
		{
			Assert::IsTrue(ShapeType::Donut == Donut::getClassShapeType());
		}

		TEST_METHOD(TestGetShapeType)
		{
			Donut c;
			Assert::IsTrue(ShapeType::Donut == c.getShapeType());
		}

		TEST_METHOD(TestGetPerimeter)
		{
			// Expect the perimeter to be zero if one of the radii is zero.
			Donut z1;
			Assert::AreEqual(0., z1.getPerimeter());
			Donut z2(3., 0.);
			Assert::AreEqual(0., z2.getPerimeter());
			Donut z3(0., 3);
			Assert::AreEqual(0., z3.getPerimeter());
			Donut z4(0., 0.);
			Assert::AreEqual(0., z4.getPerimeter());

			// Expect the perimeter to be zero if one of the radii is negative.
			Donut n1(-4., 3.);
			Assert::AreEqual(0., n1.getPerimeter());
			Donut n2(3., -4.);
			Assert::AreEqual(0., n2.getPerimeter());
			Donut n3(-4., -3.);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expect the perimeter to be zero if the internal and external radii are equal to each other.
			Donut e1(3., 3.);
			Assert::AreEqual(0., e1.getPerimeter());

			// Expect the perimeter to be 2 * pi * (ri + re) 
			// if the internal radius ri and external radus re are positive and not equal to each other.
			double ri = 3.5, re = 5.5;
			
			Donut d(ri, re);
			double expected = (ri + re) * M_PI * 2;
			double relative_error = fabs(d.getPerimeter() - expected) / expected * 100;
			double tolerance = 1.e-5;
			Assert::IsTrue(relative_error < tolerance);
		}

		TEST_METHOD(TestGetArea)
		{
			// Expect the area to be zero if one of the radii is zero
			Donut z1;
			Assert::AreEqual(0., z1.getArea());
			Donut z2(3., 0.);
			Assert::AreEqual(0., z2.getArea());
			Donut z3(0., 3);
			Assert::AreEqual(0., z3.getArea());
			Donut z4(0., 0.);
			Assert::AreEqual(0., z4.getArea());

			// Expect the area to be zero if one of the radii is negative
			Donut n1(-4., 3.);
			Assert::AreEqual(0., n1.getArea());
			Donut n2(3., -4.);
			Assert::AreEqual(0., n2.getArea());
			Donut n3(-4., -3.);
			Assert::AreEqual(0., n3.getArea());

			// Expect the area to be zero if the internal and external radii are equal to each other
			Donut e1(3., 3.);
			Assert::AreEqual(0., e1.getArea());

			// Expect the area to be (re*re - ri*ri) * pi if the internal radius ri and external radius re 
			// are positive and not equal to each other.
			double ri = 3.5, re = 5.5;
			Donut d(ri, re);
			Assert::AreEqual((re*re - ri*ri) * M_PI, d.getArea(), 1.e-5);
		}

		TEST_METHOD(TestIsValid)
		{
			// Expect false for if one of the radii is zero
			Donut z1;
			Assert::IsFalse(z1.isValid());
			Donut z2(3., 0.);
			Assert::IsFalse(z2.isValid());
			Donut z3(0., 3);
			Assert::IsFalse(z3.isValid());
			Donut z4(0., 0.);
			Assert::IsFalse(z4.isValid());

			// Expect false if one of the radii is negative
			Donut n1(-4., 3.);
			Assert::IsFalse(n1.isValid());
			Donut n2(3., -4.);
			Assert::IsFalse(n2.isValid());
			Donut n3(-4., -3.);
			Assert::IsFalse(n3.isValid());

			// Expect false if the internal and external radii are equal to each other
			Donut e1(3., 3.);
			Assert::IsFalse(e1.isValid());

			// Expect true if the internal and external radii are positive and not equal to each other.
			double ri = 3.5, re = 5.5;
			Donut d(ri, re);
			Assert::IsTrue(d.isValid());
		}


	};
}