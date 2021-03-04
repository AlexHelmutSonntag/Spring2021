#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H
#include<iostream>
#include<vector>
#include<math.h>

class Polynomial{

public:

    //Handling errors;
    enum POLYERROR {NEGATIVE_DEGREE};

    Polynomial();
    Polynomial(int degree,const std::vector<float>& vec);
    Polynomial(const Polynomial& input);
    void insert(const float &num) { _vec.push_back(num);}
    int getDegree() const { return _degree;}
    void setDegree(const int n);
    void input();
    float getCoeff( int n ) const;

    // Overloading +
    friend Polynomial operator+(const Polynomial &p1, const Polynomial &p2);

    // Overloading -
    friend Polynomial operator-(const Polynomial &p1, const Polynomial &p2);

    // Overloading *
    friend Polynomial operator*(const Polynomial &p1, const Polynomial &p2);

    // Overloading <<
    friend std::ostream &operator<<(std::ostream &os, const Polynomial &p1);

    float evaluate(float x)const;



private:
    std::vector<float> _vec;
    int _degree;
};

#endif // POLYNOMIAL_H
