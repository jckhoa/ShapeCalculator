#include "stdafx.h"
#include "CppUnitTest.h"
#include "IsoscelesTriangle.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTestIsoscelesTriangle)
	{
	public:

		TEST_METHOD(TestConstructor0)
		{
			IsoscelesTriangle tri;
			Assert::AreEqual(0., tri.getSide());
			Assert::AreEqual(0., tri.getBase());
		}

		TEST_METHOD(TestConstructor1)
		{
			IsoscelesTriangle tri(2., 3.);
			Assert::AreEqual(2., tri.getSide());
			Assert::AreEqual(3., tri.getBase());
		}

		TEST_METHOD(TestSetSize)
		{
			IsoscelesTriangle tri;
			tri.setSize(2., 3.);
			Assert::AreEqual(2., tri.getSide());
			Assert::AreEqual(3., tri.getBase());
		}

		TEST_METHOD(TestGetSide)
		{
			IsoscelesTriangle tri(2., 3.);
			Assert::AreEqual(2., tri.getSide());
		}

		TEST_METHOD(TestGetBase)
		{
			IsoscelesTriangle tri(2., 3.);
			Assert::AreEqual(3., tri.getBase());
		}

		TEST_METHOD(TestGetClassShapeType)
		{
			Assert::IsTrue(ShapeType::IsoscelesTriangle == IsoscelesTriangle::getClassShapeType());
		}

		TEST_METHOD(TestGetShapeType)
		{
			IsoscelesTriangle tri;
			Assert::IsTrue(ShapeType::IsoscelesTriangle == tri.getShapeType());
		}

		TEST_METHOD(TestGetPerimeter)
		{
			// Expect the perimeter to be zero for zero base length or zero side length
			IsoscelesTriangle z0;
			Assert::AreEqual(0., z0.getPerimeter());
			IsoscelesTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getPerimeter());
			IsoscelesTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getPerimeter());

			// Expect the perimeter to be zero for negative base length or negative side length
			IsoscelesTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getPerimeter());
			IsoscelesTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getPerimeter());
			IsoscelesTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getPerimeter());

			// Expected the perimeter to be zero for triangles where 2 * side <= base
			IsoscelesTriangle c1(2., 5.);
			Assert::AreEqual(0., c1.getPerimeter());
			IsoscelesTriangle c2(2., 4.);
			Assert::AreEqual(0., c2.getPerimeter());

			// Expect the perimeter to be 2 * side + base for positive side and base, and 2 * side > base
			IsoscelesTriangle tri(2., 3.);
			double expected = 7.;
			Assert::AreEqual(expected, tri.getPerimeter());

		}

		TEST_METHOD(TestGetArea)
		{
			// Expect the area to be zero for zero base length or zero side length
			IsoscelesTriangle z0;
			Assert::AreEqual(0., z0.getArea());
			IsoscelesTriangle z1(0., 2.);
			Assert::AreEqual(0., z1.getArea());
			IsoscelesTriangle z2(2., 0.);
			Assert::AreEqual(0., z2.getArea());

			// Expect the area to be zero for negative base length or negative side length
			IsoscelesTriangle n1(-4.2, 3);
			Assert::AreEqual(0., n1.getArea());
			IsoscelesTriangle n2(4.2, -3);
			Assert::AreEqual(0., n2.getArea());
			IsoscelesTriangle n3(-4.2, -3);
			Assert::AreEqual(0., n3.getArea());

			// Expected the area to be zero for triangles where 2 * side <= base
			IsoscelesTriangle c1(2., 5.);
			Assert::AreEqual(0., c1.getArea());
			IsoscelesTriangle c2(2., 4.);
			Assert::AreEqual(0., c2.getArea());

			// Expect positive area for positive side and base, and 2 * side > base
			IsoscelesTriangle tri(5., 6.);
			double expected = 12.;
			Assert::AreEqual(expected, tri.getArea());

		}

		TEST_METHOD(TestIsValid)
		{
			// Expect false for zero base length or zero side length
			IsoscelesTriangle z0;
			Assert::IsFalse(z0.isValid());
			IsoscelesTriangle z1(0., 2.);
			Assert::IsFalse(z1.isValid());
			IsoscelesTriangle z2(2., 0.);
			Assert::IsFalse(z2.isValid());

			// Expect false for negative base length or negative side length
			IsoscelesTriangle n1(-4.2, 3);
			Assert::IsFalse(n1.isValid());
			IsoscelesTriangle n2(4.2, -3);
			Assert::IsFalse(n2.isValid());
			IsoscelesTriangle n3(-4.2, -3);
			Assert::IsFalse(n3.isValid());

			// Expected false for triangles where 2 * side <= base
			IsoscelesTriangle c1(2., 5.);
			Assert::IsFalse(c1.isValid());
			IsoscelesTriangle c2(2., 4.);
			Assert::IsFalse(c2.isValid());

			// Expect true for triangles with positive base and side and 2 * side > base
			IsoscelesTriangle tri(5., 6.);
			Assert::IsTrue(tri.isValid());
		}
	};
}