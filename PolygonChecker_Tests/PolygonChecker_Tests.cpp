#include "pch.h"
#include "CppUnitTest.h"
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" bool triangleInequalityTheorem(int s1, int s2, int s3);
extern "C" bool analyzeFourPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int* perimeter, int* area);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(AnalyzeTriangleTests)
	{
	public:
		TEST_METHOD(Test1_analyzeTriangle_One_OneandnegativeOne_Not_a_triangle)
		{
			int side1 = 1;
			int side2 = 1;
			int side3 = -1;
			// Sides of triangle can't be negative so we are checking with negative number.
			char EXPECTED[30] = { "Not a triangle" };
			char* actual;

			actual = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test2_analyzeTriangle_One_FiveandZero_Not_a_triangle)
		{
			int side1 = 1;
			int side2 = 5;
			int side3 = 0;
			// Any side of triangle can't be zero so we are checking the function by taking zero as input.
			char EXPECTED[30] = { "Not a triangle" };
			char* actual;

			actual = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test3_analyzeTriangle_One_OneandOne_EquilateralTriangle)
		{
			int side1 = 1;
			int side2 = 1;
			int side3 = 1;
			char EXPECTED[30] = { "Equilateral triangle" };
			char* actual;

			actual = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test4_analyzeTriangle_One_OneandOne_IsoscelesTriangle)
		{
			int side1 = 1;
			int side2 = 1;
			int side3 = 2;
			char EXPECTED[30] = { "Isosceles triangle" };
			char* actual;

			actual = analyzeTriangle(side1, side2, side3);

			Assert::AreEqual(EXPECTED, actual);

		}
	};
	TEST_CLASS(TriangleInequalityTheoremTests)
	{
		public:
		TEST_METHOD(Test5_triangleInequalityTheorem_One_OneandFour_false)
		{
			int s1 = 1;
			int s2 = 1;
			int s3 = 4;
			bool EXPECTED = false;
			bool actual;

			actual = triangleInequalityTheorem(s1, s2, s3);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test6_triangleInequalityTheorem_One_OneandTwo_false)
		{
			int s1 = 1;
			int s2 = 1;
			int s3 = 2;
			bool EXPECTED = false;
			bool actual;

			actual = triangleInequalityTheorem(s1, s2, s3);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test7_triangleInequalityTheorem_Four_FiveandSix_true)
		{
			int s1 = 4;
			int s2 = 5;
			int s3 = 6;
			bool EXPECTED = true;
			bool actual;

			actual = triangleInequalityTheorem(s1, s2, s3);

			Assert::AreEqual(EXPECTED, actual);

		}
	};
}
