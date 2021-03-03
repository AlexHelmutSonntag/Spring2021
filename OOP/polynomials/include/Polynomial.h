#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


#include "Polynomial.h"
#include<vector>
#include<math.h>

class Polynomial{

public:

    enum PolynomialError{WRONG_DEGREE};
    int getSize();
    Polynomial();
    Polynomial(int degree,const std::vector<double>& vec);
    Polynomial(const Polynomial& input);
    Polynomial multiply(const Polynomial& p1);
    Polynomial add(const Polynomial& p1);
    Polynomial subtract(const Polynomial& p1);
    double evaluate(double x);
    void print();



private:
    std::vector<double> _vec;
    int _degree=0;
};

#endif // POLYNOMIAL_H
