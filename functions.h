#ifndef __FUNCTIONS_H__
#define __FUNCTIONS_H__

#include <iostream>
#include <cmath>
#include <string>

//-------------------------------------------------------------------------------------------------

#define INFINITY_OF_ROOTS -1
#define FINITE_ERROR -2
#define ACCURACY 1E-8

//-------------------------------------------------------------------------------------------------

int IsZero(double x);

int ReadData(double &a, double &b, double &c);

int SolveLinearEquation(double b, double c, double &root1);

int SolveQuadraticEquation(double a, double b, double c, double &root1, double &root2);

void PrintAnswer(int rootsNumber, double root1, double root2);

//-------------------------------------------------------------------------------------------------

#endif
