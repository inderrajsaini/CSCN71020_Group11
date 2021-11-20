#include "pch.h"
#include "CppUnitTest.h"
extern "C" char* analyzeTriangle(int side1, int side2, int side3);
extern "C" bool triangleInequalityTheorem(int s1, int s2, int s3);
extern "C" double calcAngle(int adjSide1, int adjSide2, int oppSide);
extern "C" bool analyzeFourPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int* perimeter, int* area);
extern "C" int findDistBw2Pts(int x1, int y1, int x2, int y2);
extern "C" bool isSquare(int sqOfDiagonal, int sqOfSide);
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
			bool EXPECTED = true;
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
	TEST_CLASS(TriangleInsideAngleTests)
	{
	public:
		
		//Test for inside angles of scalene triangle
		TEST_METHOD(Test1_calcAngle_One_TwoandThree_180)
		{
			int s1 = 1;
			int s2 = 2;
			int s3 = 3;

			int EXPECTED = 180;
			int actual;

			actual = calcAngle(s1, s2, s3);

			Assert::AreEqual(EXPECTED, actual);
		}
		//Test for inside angles of equilateral triangle
		TEST_METHOD(Test2_calcAngle_Three_ThreeandThree_60)
		{
			int s1 = 3;
			int s2 = 3;
			int s3 = 3;

			int EXPECTED = 60;
			int actual;

			actual = calcAngle(s1, s2, s3);

			Assert::AreEqual(EXPECTED, actual);
		}
		//Test for inside angles of isosceles triangle
		TEST_METHOD(Test3_calcAngle_One_TwoandThree_60)
		{
			int s1 = 1;
			int s2 = 2;
			int s3 = 1;

			int EXPECTED = 0;
			int actual;

			actual = calcAngle(s1, s2, s3);

			Assert::AreEqual(EXPECTED, actual);
		}
	};
	TEST_CLASS(AnalyzeFourPointsTests)
	{
	public:
		TEST_METHOD(Test1_1_findDistBw2Pts_Three_One_TwoandFour_Ten)
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 2;
			int y2 = 4;
			int EXPECTED = 10;
			int actual;

			actual = findDistBw2Pts(x1, y1, x2, y2);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test1_2_findDistBw2Pts_negativeThree_One_TwoandFour_ThirtyFour)
		{
			int x1 = -3;
			int y1 = 1;
			int x2 = 2;
			int y2 = 4;
			int EXPECTED = 34;
			int actual;

			actual = findDistBw2Pts(x1, y1, x2, y2);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test1_3_findDistBw2Pts_Zero_Onea_TwondFour_Thirteen)
		{
			int x1 = 0;
			int y1 = 1;
			int x2 = 2;
			int y2 = 4;
			int EXPECTED = 13;
			int actual;

			actual = findDistBw2Pts(x1, y1, x2, y2);

			Assert::AreEqual(EXPECTED, actual);

		}
		TEST_METHOD(Test2_1_isSquare_Three_One_TwoandFour_Ten)
		{
			int x1 = 3;
			int y1 = 1;
			int x2 = 2;
			int y2 = 4;
			int EXPECTED = 10;
			int actual;

			actual = findDistBw2Pts(x1, y1, x2, y2);

			Assert::AreEqual(EXPECTED, actual);

		}
	};
}
