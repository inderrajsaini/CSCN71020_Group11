#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include "rectangleSolver.h"

// returns true if the 4 points make a rectangle, and sets the perimeter and area of the rectangle
// point i has the coordinates xi,yi
bool analyzeFourPoints(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int* perimeter, int* area)
{
    int sqDist[6];
    sqDist[0] = findDistBw2Pts(x1, y1, x2, y2);
    sqDist[1] = findDistBw2Pts(x1, y1, x3, y3);
    sqDist[2] = findDistBw2Pts(x1, y1, x4, y4);
    sqDist[3] = findDistBw2Pts(x2, y2, x3, y3);
    sqDist[4] = findDistBw2Pts(x2, y2, x4, y4);
    sqDist[5] = findDistBw2Pts(x3, y3, x4, y4);

    int count = 0;
    int unique = 0;

    int uniqSqDist[6];

    //finding distinct squared distances, and storing them in uniqSqDist array
    for (int i = 0; i < 6; i++)
    {
        count = 0;
        for (int j = 0; j <= i; j++)
        {
            if (sqDist[i] == sqDist[j])
                count++;
        }
        if (count == 1)
        {
            uniqSqDist[unique] = sqDist[i];
            unique++;
        }
    }

    if (unique > 3) // not a rectangle
        return false;
    if (unique == 2) // might be a square
    {
        int diagonal, sqOfSide;
        if (uniqSqDist[0] > uniqSqDist[1])
        {
            diagonal = uniqSqDist[0];
            sqOfSide = uniqSqDist[1];
        }
        else
        {
            diagonal = uniqSqDist[1];
            sqOfSide = uniqSqDist[0];
        }

        if (isSquare(diagonal, sqOfSide)) //if square of diagonal is 2 times the square of side
        {
            *perimeter = 4 * sqrt(sqOfSide);
            *area = sqOfSide;
            return true; //returns true because a square is also a rectangle
        }
        else
            return false;
    }
    else if (unique == 3) //might be a rectangle
    {
        int sqLength, sqBreadth; int sqDiagonal;
        setLengthBreadthAndDiagonal(uniqSqDist[0], uniqSqDist[1], uniqSqDist[2], &sqLength, &sqBreadth, &sqDiagonal);
        if (sqLength + sqBreadth == sqDiagonal) { //using pythagoras theorem to check if sides makes a 90 degree angle
            int length = sqrt(sqLength);
            int breadth = sqrt(sqBreadth);
            *perimeter = 2 * (length + breadth);
            *area = length * breadth;
            return true;
        }
        else
            return false;
    }
    return false;

}


    //returns squared distance between 2 cartesian points
    int findDistBw2Pts(int x1, int y1, int x2, int y2)
    {
        int sqDist = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
        return sqDist;
    }

    bool isSquare(int sqOfDiagonal, int sqOfSide)
    {
        return sqOfDiagonal == 2 * sqOfSide;
    }
    //sets the largest of 3 lengths to diagonal, and other two as length and breadth
    void setLengthBreadthAndDiagonal(int a, int b, int c, int* length, int* breadth, int* diagonal) {
        if (a > b && a > c)
        {
            *diagonal = a;
            *length = b;
            *breadth = c;
        }
        else if (b > a && b > c)
        {
            *diagonal = b;
            *length = a;
            *breadth = c;
        }
        else
        {
            *diagonal = c;
            *length = b;
            *breadth = a;
        }
    }