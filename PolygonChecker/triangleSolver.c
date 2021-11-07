#include <stdio.h>
#include <stdbool.h>
#include "triangleSolver.h"


char* analyzeTriangle(int side1, int side2, int side3) {
	char* result = "";
	if (side1 <= 0 || side2 <= 0 || side3 <= 0) {
		result = "Not a triangle";
	}
	else if (side1 == side2 && side1 == side3) {
		result = "Equilateral triangle";
	}
	else if ((side1 == side2 && side1 != side3) || 
		(side1 == side3 && side1 != side2))
	{
		result = "Isosceles triangle";
	}
	else {
		result = "Scalene triangle";
	}

	return result;
}

bool triangleInequalityTheorem(int s1, int s2, int s3)
{
	bool isTriangle = false;
	if ((s1 + s2 > s3) && (s2 + s3 > s1) && (s1 + s3 > s2))
		isTriangle = true;
	return isTriangle;

}
