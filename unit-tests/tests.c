#include <stdio.h>
#include <math.h>
#include "equat.h"

void unitTest(int testNum, double a, double b, double c, int out, double _x1, double _x2);

void tests()
{
    printf("\nLinear equat tests\n");
    unitTest(1, 0, 2, -2, 1, 1.0, NAN);
    unitTest(2, 0, 0, -2, NO_ROOTS, NAN, NAN);
    unitTest(3, 0, 0, 0, INF_ROOTS, NAN, NAN);
    unitTest(4, 0, 5, -10, 1, 2.0, NAN);
    unitTest(5, 0, 5, 0, 1, 0, NAN);
    unitTest(6, 0, 2000000000, 5000000000, 1, -2.5, NAN);
    unitTest(7, 0, 0.001, 2000000000, 1, -2000000000000, NAN);
    unitTest(8, 0, 9, -3, 1, 1.0/3.0 , NAN);

    printf("\nQuadratic equat tests\n");
    unitTest(1, 1, 0, -4, 2, 2, -2);
    unitTest(2, 1, 0, 4, NO_ROOTS, NAN, NAN);
    unitTest(3, 8, -4, 0, 2, 0.5, 0);
    unitTest(4, 3, -27, 60, 2, 5, 4);
    unitTest(5, 20, 4, 400, NO_ROOTS, NAN, NAN);
    unitTest(6, 600000000, -5400000000, 12000000000, 2, 5, 4);
    unitTest(6, 1, -6, 9, 1, 3, NAN);
    printf("\n");

}

void unitTest(int testNum, double a, double b, double c, int out, double _x1, double _x2)
{
    double x1 = NAN, x2 = NAN;
    int numRoots = squareEquat(a, b, c, &x1, &x2);
    if (numRoots != out || ( x1 != _x1 && !isnan(x1) && !isnan(_x1) ) || ( x2 != _x2 && !isnan(x2) && !isnan(_x2)) )
        printf("#%d There is mistake! numRoots = %d x1 = %lg x2 = %lg instead numRoots = %d x1 = %lg x2 = %lg\n",
            testNum,                  out,         _x1,     _x2,              numRoots,     x1,      x2        );
    else
        printf("#%d OK\n", testNum);

}
