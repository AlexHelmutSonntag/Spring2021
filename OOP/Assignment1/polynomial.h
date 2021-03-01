#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H



#include "polynomial.h"
#include<vector>
#include<math.h>

class Polynomial{

public:

    enum PolynomialError{WRONG_DEGREE};
    int getSize();
    Polynomial();
    Polynomial(int degree,const std::vector<double>& vec);
    /*Polynomial setCoeff(int degree,double num);*/
    Polynomial multiply(const Polynomial& p1);
    Polynomial add(const Polynomial& p1);
    Polynomial subtract(const Polynomial& p1);
    double evaluate(double x);
    void print();



private:
    std::vector<double> _vec;
    int _degree;
};

#endif // POLYNOMIAL_H
