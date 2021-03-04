#include <iostream>
#include<vector>

#include "Polynomial.h"
#include "Menu.h"

#define NORMAL_MODE
#ifdef NORMAL_MODE

using namespace std;

int main()
{
    Menu test;
    test.run();

    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("Assignment")
{
    Polynomial p1,p2,p3;

    //Inserting Coefficients

    p1.setDegree(2);
    p1.insert(1);
    p1.insert(2);
    p1.insert(3);

    p2 = p1;
    //Checking degree and Coefficients

    CHECK(p1.getDegree() == p2.getDegree());
    CHECK(p1.getCoeff(2)== p2.getCoeff(2));
    CHECK(p1.getCoeff(1)== p2.getCoeff(1));
    CHECK(p1.getCoeff(0)== p2.getCoeff(0));


    p3 = p2;
    //Checking degree and Coefficients

    CHECK(p2.getDegree() == p3.getDegree());
    CHECK(p2.getCoeff(2)== p3.getCoeff(2));
    CHECK(p2.getCoeff(1)== p3.getCoeff(1));
    CHECK(p2.getCoeff(0)== p3.getCoeff(0));


}
TEST_CASE("Copying Value")
{
    Polynomial p1,p2;

    p1.setDegree(3);
    //Inserting Coefficients
    p1.insert(3);
    p1.insert(2);
    p1.insert(1);
    p1.insert(1);


    p2 =p1;

    //Checking degree and Coefficients
    CHECK(p1.getDegree()==p2.getDegree());
    CHECK(p1.getCoeff(0)==p2.getCoeff(0));
    CHECK(p1.getCoeff(1)==p2.getCoeff(1));
    CHECK(p1.getCoeff(2)==p2.getCoeff(2));
    CHECK(p1.getCoeff(3)==p2.getCoeff(3));

}
TEST_CASE("Degree TEST"){

    Polynomial p1;
    //Inserting Coefficients
    p1.setDegree(2);
    p1.insert(4);
    p1.insert(3);
    p1.insert(2);
    //Checking degree and Coefficients
    CHECK(p1.getDegree() == 2);
    CHECK(p1.getCoeff(2) == 4);
    CHECK(p1.getCoeff(1) == 3);
    CHECK(p1.getCoeff(0) == 2);


}
TEST_CASE("Adding"){
    Polynomial p1,p2,p3;

    p1.setDegree(2);
    p1.insert(3);
    p1.insert(2);
    p1.insert(1);

    p2.setDegree(2);
    p2.insert(3);
    p2.insert(2);
    p2.insert(1);

//2x^2+4x+6

    p3 = p1+p2;

    CHECK(p3.getDegree()==2);
    CHECK(p3.getCoeff(2)==6);
    CHECK(p3.getCoeff(1)==4);
    CHECK(p3.getCoeff(0)==2);
}
TEST_CASE("Subtracting"){
    Polynomial p1,p2,p3;

    p1.setDegree(2);
    p1.insert(4);
    p1.insert(1);
    p1.insert(5);

    p2.setDegree(2);
    p2.insert(3);
    p2.insert(2);
    p2.insert(1);

//4x^2-x +1

    p3 = p1-p2;

    CHECK(p3.getDegree()==2);
    CHECK(p3.getCoeff(2)==1);
    CHECK(p3.getCoeff(1)==-1);
    CHECK(p3.getCoeff(0)==4);
}
TEST_CASE("Multiplication"){
    Polynomial p1,p2,p3;

    p1.setDegree(1);

    p1.insert(1);
    p1.insert(3);

    p2.setDegree(1);
    p2.insert(1);
    p2.insert(2);

    p3 = p1*p2;

    CHECK(p3.getDegree()==2);
    CHECK(p3.getCoeff(0)==6);
    CHECK(p3.getCoeff(1)==5);
    CHECK(p3.getCoeff(2)==1);


}
TEST_CASE("Evaluate"){
    Polynomial p1;
    p1.setDegree(2);
    p1.insert(3);
    p1.insert(1);
    p1.insert(2);
    CHECK(p1.evaluate(2) ==16);
}

#endif

