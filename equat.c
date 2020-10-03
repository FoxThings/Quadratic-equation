#include "equat.h"
#include <math.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

const double EPSILON = 0.000001d;

bool isZero(double d)
{
    if (fabs(d) < EPSILON)
        return true;
    return false;
}

int lineEquat(double k, double l, double *x)
{
    assert(!isinf(k));
    assert(!isinf(l));

    assert(!isnan(k));
    assert(!isnan(l));

    assert(x != NULL);

    if (k == 0)
    {
        if (l == 0)
            return INF_ROOTS;
        else
            return NO_ROOTS;
    }

    *x = -l / k;
    return 1;
}

int squareEquat(double a, double b, double c, double *x1, double *x2)
{
    assert(!isinf(a));
    assert(!isinf(b));
    assert(!isinf(c));

    assert(!isnan(a));
    assert(!isnan(b));
    assert(!isnan(c));

    assert(x1 != NULL);
    assert(x2 != NULL);

    if (a == 0)
    {
        return lineEquat(b, c, x1);
    }

    double d = b * b - 4 * a * c;

    if (isZero(d))
    {
        *x1 = -b / 2 * a;
        return 1;
    }
    else if (d < 0)
    {
        return NO_ROOTS;
    }

    double rootDis = sqrt(d);
    *x1 = (-b + rootDis) / (2 * a);
    *x2 = (-b - rootDis) / (2 * a);
    return 2;
}


