#include "polynomial.h"
#include< iostream>
using namespace std;

Polynomial::Polynomial()
{
    _degree = 0;
    _vec.resize(0);
}
Polynomial::Polynomial(int degree)
{
    _degree = degree;
    _vec.resize(_degree);
}
void Polynomial:: setCoeff(int degree, double num){
    if (degree<=0|| degree >_degree){
        return -1;    
    }
    else{
        _vec[degree] = num;
    }
}
void Polynomial::print(){
    
    for (int i = _degree; i >=0; i--)
    {
        if(_vec[i]>=0)
        {
            cout<<"+";
        }
        cout<<_vec[i]<<"X^" <<i;
    }
}

Polynomial Polynomial::add(Polynomial p1, Polynomial p2){
    
    Polynomial return_Poly;
    /*if(p1._degree == p2._degree)*/
    {
        for(int i =p1._degree;i>=0;i--)
        {
            return_Poly._vec[i]= p1._vec[i]+ p2._vec[i]; 
        }
    }
    return return_Poly;
}


Polynomial Polynomial::subtract(Polynomial p1, Polynomial p2){
    
    Polynomial return_Poly;
    // if(p1._degree == p2._degree)
    {
        for(int i =p1._degree;i>=0;i--)
        {
            return_Poly._vec[i]= p1._vec[i]- p2._vec[i]; 
        }
    }
    return return_Poly;
}
double Polynomial:: evaluate(double x)
{
    double result=0;
    for(int i =_degree;i>0;i--)
    {
        result+=pow(x,i) *_vec[i];
    }
    result+=_vec[0];
    
    return result;
}
