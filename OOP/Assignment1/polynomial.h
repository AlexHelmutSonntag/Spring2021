#ifndef POLYNOMIAL_H_INCLUDED
#define POLYNOMIAL_H_INCLUDED

#include "polynomial.h"
#include<vector>
#include<math.h>
#include< iostream>

class Polynomial{

public:

    int getSize();
    Polynomial();
    Polynomial(int degree);
    void setCoeff(int degree,double num);
    Polynomial multiply(Polynomial p1, Polynomial p2);
    Polynomial add(Polynomial p1, Polynomial p2);
    Polynomial subtract(Polynomial p1, Polynomial p2);
    double evaluate(double x);
    void print();

    

private:
    std::vector<double> _vec;
    int _degree;
};
#endif // POLYNOMIAL_H_INCLUDED
