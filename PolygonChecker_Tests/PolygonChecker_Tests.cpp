#include "pch.h"
#include "CppUnitTest.h"
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" bool triangleInequalityTheorem(int s1, int s2, int s3);
extern "C" bool analyzeFourPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int* perimeter, int* area);
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolygonCheckerTests
{
	TEST_CLASS(PolygonCheckerTests)
	{
	public:
		
		TEST_METHOD(Test1_analyzeTriangle_One_OneandnegativeOne_Not_a_triangle)
		{
			int side1 = 1;
			int side2 = 1;
			int side3 = -1;
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
			char EXPECTED[30] = { "Equilateral Triangle" };
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
}
