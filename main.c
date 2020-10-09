#include <stdio.h>
#include <math.h>
#include "equat.h"

// #include "tests.h" use it if you want to get tests lib

int main()
{
    // tests(); invoke unit-tests

    printf("-> Square equations calculator!\n");
    printf("-> Zvezdin Nikita 2020, all rights reserved(C)\n\n");

    printf("[a]x^2 + [b]x + [c] = 0\n");
    printf("Please, enter (a, b and c): ");

    double a = NAN, b = NAN, c = NAN;
    const int INPUT_COUNT = 3;
    int attempts = 3;

    while(scanf("%lg %lg %lg", &a, &b, &c) != INPUT_COUNT)
    {
        --attempts;
        if (attempts <= 0)
        {
            printf("Your attempts are over!\n\n");
            return -1;
        }
        printf("Sorry, something wrong. Please, try again!\n");
        printf("[a]x^2 + [b]x + [c] = 0\n");
        printf("Please, enter (a, b and c): ");
        scanf("%*[^\n]%*c"); // Flushing standard input buffer
    }

    double x1 = NAN, x2 = NAN;
    int numRoots = squareEquat(a, b, c, &x1, &x2);

    switch (numRoots)
    {
    case 1:
        printf("Your root: x = %lg", x1);
        break;
    case 2:
        printf("Your roots: x1 = %lg, x2 = %lg", x1, x2);
        break;
    case INF_ROOTS:
        printf("There are inf roots!");
        break;
    case NO_ROOTS:
        printf("There are no roots!");
        break;
    default :
        printf("Wrong roots!");
        break;
    }

    printf("\n\n");
    return 0;
}
