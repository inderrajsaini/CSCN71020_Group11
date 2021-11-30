#include <stdio.h>
#include <stdbool.h>
#include "triangleSolver.h"
#include<math.h>
#define pi 3.141592653589793238

char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle\n";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle\n";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle\n";
	}
	else {
		result = "Scalene triangle\n";
	}

	return result;
}

bool triangleInequalityTheorem(int s1, int s2, int s3)
{
	bool isTriangle = false;
	if ((s1 + s2 >= s3) && (s2 + s3 >= s1) && (s1 + s3 >= s2))
		isTriangle = true;
	return isTriangle;

}

void calculateIntAnglesOfTriangle(int s1, int s2, int s3)
{
	double s1s2Angle, s2s3Angle, s3s1Angle;
	s1s2Angle = calcAngle(s1, s2, s3);
	s2s3Angle = calcAngle(s2, s3, s1);
	s3s1Angle = 180 - (s1s2Angle + s2s3Angle);
	printf("The angles of the triangle are: %lf, %lf, %lf degrees.\n", s1s2Angle, s2s3Angle, s3s1Angle);
}

double calcAngle(int adjSide1, int adjSide2, int oppSide)
{
	double angle = (double)(adjSide1 * adjSide1 + adjSide2 * adjSide2 - oppSide * oppSide) / (2 * adjSide1 * adjSide2);
	return convertRadToPi(acos(angle));
}

double convertRadToPi(double radians)
{
	return radians * (180 / pi);
}
