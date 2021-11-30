#include <stdio.h>
#include <stdbool.h>

#include "main.h"
#include "triangleSolver.h"
#include "rectangleSolver.h"
int* getFourPoints(int* cartesianPoints);


int main() {
	bool continueProgram = true;
	while (continueProgram) {
		printWelcome();

		int shapeChoice = printShapeMenu();

		switch (shapeChoice)
		{
		case 1:
			printf_s("Triangle selected.\n");
			int triangleSides[3] = { 0, 0, 0 };
			int* triangleSidesPtr = getTriangleSides(triangleSides);
			
			char* result = analyzeTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			printf_s("%s\n", result);
			
			bool isTriangle = triangleInequalityTheorem(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			if (isTriangle) {
				printf("It is a legitimate triangle!\n\n");
				calculateIntAnglesOfTriangle(triangleSidesPtr[0], triangleSidesPtr[1], triangleSidesPtr[2]);
			}
			/*else
				printf("Not a legitimate triangle!\n\n");*/

			break;
		case 2:
			printf_s("\nRectangle selected.\n");

			int points[8] = { 0,0,0,0,0,0,0,0};
			int perimeter, area;
			int* cartesianPoints = getFourPoints(points);

			bool isRectangle = analyzeFourPoints(cartesianPoints[0], cartesianPoints[1], cartesianPoints[2], cartesianPoints[3], cartesianPoints[4], cartesianPoints[5], cartesianPoints[6], cartesianPoints[7], &perimeter, &area);
			if (isRectangle)
			{
				printf("It is a rectangle!\n\n");
				printf("Perimeter = %d\nArea = %d\n", perimeter, area);
			}
			else
				printf("NOT a rectangle!\n\n");
			
			break;
		case 0:
			continueProgram = false;
			printf("\nEXITING........................\n");
			break;
		default:
			printf_s("Invalid value entered.\n");
			break;
		}
	}
	return 0;
}

void printWelcome() {
	printf_s("\n");
	printf_s(" **********************\n");
	printf_s("**     Welcome to     **\n");
	printf_s("**   Polygon Checker  **\n");
	printf_s(" **********************\n");
}

int printShapeMenu() {
	printf_s("1. Triangle\n");
	printf_s("2. Rectangle\n");
	printf_s("0. Exit\n");

	int shapeChoice;

	printf_s("\nEnter number: ");
	scanf_s("%1o", &shapeChoice);

	return shapeChoice;
}

int* getTriangleSides(int* triangleSides) {
	printf_s("Enter the three sides of the triangle: ");
	for (int i = 0; i < 3; i++)
	{
		scanf_s("%d", &triangleSides[i]);
	}
	return triangleSides;
}

//saves the 4 cartesian points in an array of 8 integers
int* getFourPoints(int* cartesianPoints) {
	printf_s("Enter the four points of the rectangle: \n");
	int index = 0;
	for (int i = 1; i < 5; i++)
	{
		printf_s("Enter the x coordinate of point %d: ", i);
		scanf_s("%d", &cartesianPoints[index]);
		index++;
		printf_s("Enter the y coordinate of point %d: ", i);
		scanf_s("%d", &cartesianPoints[index]);
		index++;
	}
	return cartesianPoints;
}