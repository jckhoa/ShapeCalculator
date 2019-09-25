#include "stdafx.h"
#include "CppUnitTest.h"
#include "Square.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestSquare)
	{
	public:

		TEST_METHOD(TestConstructor0)
		{
			Square rec;
			Assert::AreEqual(0., rec.getSideLength());
		}

		TEST_METHOD(TestConstructor1)
		{
			Square rec(2.);
			Assert::AreEqual(2., rec.getSideLength());
		}

		TEST_METHOD(TestSetSize)
		{
			Square rec;
			rec.setSize(2.);
			Assert::AreEqual(2., rec.getSideLength());
		}

		TEST_METHOD(TestGetSideLength)
		{
			Square rec(2.);
			Assert::AreEqual(2., rec.getSideLength());
		}

		TEST_METHOD(TestGetClassShapeType)
		{
			Assert::IsTrue(ShapeType::Square == Square::getClassShapeType());
		}

		TEST_METHOD(TestGetShapeType)
		{
			Square rec;
			Assert::IsTrue(ShapeType::Square == rec.getShapeType());
		}

		TEST_METHOD(TestGetPerimeter)
		{
			// Expect the perimeter to be zero for zero side length.
			Square z0;
			Assert::AreEqual(0., z0.getPerimeter());
			Square z1(0.);
			Assert::AreEqual(0., z1.getPerimeter());
			
			// Expect the perimeter to be zero for negative side length.
			Square n1(-4.2);
			Assert::AreEqual(0., n1.getPerimeter());
			
			// Expect perimeter to be 4 * side for positive side length.
			Square rec(3.);
			double expected = 12.;
			Assert::AreEqual(expected, rec.getPerimeter());

		}

		TEST_METHOD(TestGetArea)
		{
			// Expect the area to be zero for zero side length.
			Square z0;
			Assert::AreEqual(0., z0.getArea());
			Square z1(0.);
			Assert::AreEqual(0., z1.getArea());
			
			// Expect the area to be zero for negative side length.
			Square n1(-4.2);
			Assert::AreEqual(0., n1.getArea());
			
			// Expect area to be side * side for positive side length.
			Square rec(3.);
			double expected = 9.;
			Assert::AreEqual(expected, rec.getArea());

		}

		TEST_METHOD(TestIsValid)
		{
			// Expect false for zero side length.
			Square z0;
			Assert::IsFalse(z0.isValid());
			Square z1(0.);
			Assert::IsFalse(z1.isValid());
			
			// Expect false for negative side length.
			Square n1(-4.2);
			Assert::IsFalse(n1.isValid());
			
			// Expect true for positive side length.
			Square rec(3.);
			Assert::IsTrue(rec.isValid());

		}
	};
}