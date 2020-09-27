#ifndef EQUAT_H_INCLUDED
#define EQUAT_H_INCLUDED
//! @file

enum Roots  {
                INF_ROOTS = -1,
                NO_ROOTS
            };

/*!
    Calculate simple linear equations!
    @param[in] k angular coefficient
    @param[in] l shift
    @param[out] x root of equation

    @return number of roots

    @version 1.0
    @authors Zvezdin Nikita
    @warning Don't off the asserts

*/
int lineEquat(double k, double l, double *x);

/*!
    Calculate square equations!
    @param[in] a first coefficient
    @param[in] b second coefficient
    @param[in] c free coefficient
    @param[out] x1 first root of equation
    @param[out] x2 second root of equation

    @return number of roots

    @version 1.0
    @authors Zvezdin Nikita
    @warning Don't off the asserts

*/
int squareEquat(double a, double b, double c, double *x1, double *x2);

#endif // EQUAT_H_INCLUDED
