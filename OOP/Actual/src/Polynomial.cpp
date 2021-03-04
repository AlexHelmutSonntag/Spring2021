#include "Polynomial.h"
#include<iostream>
#include<vector>
using namespace std;

void Polynomial::setDegree(const int n)
{
        _degree = n;
}
float Polynomial::getCoeff(int num) const
{
    float coeff;
   if ( num > _degree ) coeff = -1.0;

   else coeff = _vec.at(_degree - num);

    return coeff;
}

Polynomial::Polynomial()
{

}

Polynomial::Polynomial(const Polynomial& input)
{
    _degree = input._degree;
    _vec = input._vec;

}

Polynomial::Polynomial(int degree,const std::vector<float>& vec)
{

    if(vec.size()<=0||degree>vec.size()) throw NEGATIVE_DEGREE;
    else{
    _degree = degree;

    for (int  i = 0; i < vec.size(); i++)
    {
        insert(vec[i]);
    }
   
    }
}


void Polynomial:: input()
{
    cout<<"Please input the degree of your polynomial: "<<endl;
    cin>>_degree;

    if(_degree<0) throw Polynomial::NEGATIVE_DEGREE;
    else {
        float coeff;
        for (int i=_degree;i>0;i--){
            cout<<"Please input the coefficient X^"<<i<<endl;
            cin>>coeff;
            insert(coeff);
        }
        cout<<"We still need the coefficient X^0 (Your Constant): "<<endl;
        cin>>coeff;
        insert(coeff);
    }
}



std::ostream &operator<<(std::ostream &os, const Polynomial &p1)
{
    int i;
    os << p1.getCoeff(p1.getDegree())<<"X^"<<p1.getDegree();
    for (i = p1.getDegree()-1;i>0;i--)
    {
        if (p1.getCoeff(i)<0.0)
        {
            os << p1.getCoeff(i)<<"X^"<<i;
        }
        else
        {
            os <<"+"<< p1.getCoeff(i)<<"X^"<<i;
        }
    }
    if (p1.getCoeff(i)< 0.0)
        os << p1.getCoeff(i)<<"\n";
    else
        os <<"+"<<p1.getCoeff(i)<<"\n";
   return os;
}


Polynomial operator+(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial return_Poly;
    if (p1.getDegree()>p2.getDegree())
    {
        return_Poly.setDegree(p1.getDegree());
    }
    else
    {
        return_Poly.setDegree(p2.getDegree());
    }
    for (int i= return_Poly.getDegree();i>=0;i--)
    {

        return_Poly.insert(p1.getCoeff(i)+p2.getCoeff(i));
    }

    return return_Poly;
}


Polynomial operator-(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial return_Poly;
    if (p1.getDegree()>p2.getDegree())
    {
        return_Poly.setDegree(p1.getDegree());
    }
    else
    {
        return_Poly.setDegree(p2.getDegree());
    }
    for (int i= return_Poly.getDegree();i>=0;i--)
    {

        return_Poly.insert(p1.getCoeff(i)-p2.getCoeff(i));
    }

    return return_Poly;
}


Polynomial operator*(const Polynomial &p1, const Polynomial &p2)
{
    Polynomial return_Poly;

    int x = p1.getDegree();
    int y = p2.getDegree();
    return_Poly.setDegree(x+y);

    vector<int> temp;
    temp.resize(x+y+1);

    for (int i = 0;i<=x;i++)
    {
        for (int j = 0 ;j<=y;j++)
        {
            temp[i+j] += (p1.getCoeff(i)*p2.getCoeff(j));
        }
    }
    for (int i=x+y;i>=0;i--)
    {
        return_Poly.insert(temp[i]);
    }
    return return_Poly;
}


float Polynomial:: evaluate(float x)const
{
    float result=_vec[0];
    for(int i =1;i<=_degree;i++)
    {
        result= _vec[i]+result*x;
    }
    
    return result;
}

