#include "Polynomial.h"
#include<iostream>
using namespace std;

Polynomial::Polynomial()
{
    _degree = 0;
    _vec.resize(0);
}
Polynomial::Polynomial(const Polynomial& input)
{
    _degree = input._degree;
    _vec = input._vec;

}

Polynomial::Polynomial(int degree,const std::vector<double>& vec)
{
    if(vec.size()<=0||degree>vec.size()) throw WRONG_DEGREE;
    else{
    _degree = degree;
    _vec.resize(vec.size());
    for (int  i = 0; i < vec.size(); i++)
    {
        _vec.push_back(vec[i]);
    }

    }
}

int Polynomial :: getSize(){
    return _vec.size();
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
    cout<<endl;
}
Polynomial Polynomial:: multiply(const Polynomial &p1){
    Polynomial return_poly;
    int m = _vec.size();
    int n = p1._vec.size();

    int limit = m + n -1;
    return_poly._vec.resize(limit);

    for (int i =0;i<limit;i++)
    {
        return_poly._vec[i] = 0;
    }
    for (int i =0 ;i<m;i++)
    {
        for (int j =0;j<n;j++)
        {
            return_poly._vec[i]+= _vec[i]*p1._vec[j];
        }
    }
    return return_poly;


}
Polynomial Polynomial::add(const Polynomial& p1){

    Polynomial return_Poly;
    if(p1._degree!=_degree) throw WRONG_DEGREE;
    else
    {
        for(int i =p1._degree;i>=0;i--)
        {
            _vec[i]+=p1._vec[i];
        }
    }
    return return_Poly;
}


Polynomial Polynomial::subtract(const Polynomial& p1){

    Polynomial return_Poly;
    if(p1._degree!=_degree) throw WRONG_DEGREE;
    else
    {
        for(int i =p1._degree;i>=0;i--)
        {
            _vec[i]-= p1._vec[i];
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

