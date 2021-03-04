#include <iostream>
#include <algorithm>
#include <sstream>
#include "Menu.h"
#include "Polynomial.h"
#define menuCount 4

using namespace std;


void Menu:: run()
{
    int v;
    do{
        v = printMenu();
        switch(v)
        {
            case 1:
                addMenu();
                break;
            case 2:
                subtractMenu();
                break;
            case 3:
                multiplyMenu();
                break;
            case 4:
                evaluateMenu();
                break;
            default:
                cout<<"\nGoodbye!\n";
                break;

        }
    }while(v!=0);

}

int Menu::printMenu()
{
    //int response;
    cout<<"\n****************************************\n";
    cout<<"0 Exit\n";
    cout<<"1. Add\n";
    cout<<"2. Subtract\n";
    cout<<"3. Multiply\n";
    cout<<"4. Evaluate\n";
    cout<<"****************************************\n";
    //produce error message

    int s=0;
    do {

    cout<<"It has to be a number between 0 and "<<menuCount<<"!"<<endl;
    cin>>s;
    }

    while(s<0 || s> menuCount);

    return s;
}


void Menu :: addMenu(){
    Polynomial p1,p2;
    try{
    p1.input();
    p2.input();
    cout<<"P1 + P2 = "<<p1+p2<<endl;
    }catch(Polynomial::POLYERROR error){
        if(error ==Polynomial::NEGATIVE_DEGREE){
            cerr<<"You inserted a negative degree!"<<endl;
        }
        else
            cerr<<"Unexpected Error. Running diagnostics.."<<endl;
    }


}


void Menu :: subtractMenu(){
    Polynomial p1,p2;
    try{
    p1.input();
    p2.input();
    cout<<"P1 - P2 = "<<p1-p2<<endl;
    }catch(Polynomial::POLYERROR error){
        if(error == Polynomial::NEGATIVE_DEGREE){
            cerr<<"You inserted a negative degree!"<<endl;
        }
        else
            cerr<<"Unexpected Error. Running diagnostics.."<<endl;
    }



}

void Menu::multiplyMenu(){
    Polynomial p1,p2;
    try{
    p1.input();
    p2.input();
    cout<<"P1 * P2 = "<<p1*p2<<endl;
    }catch(Polynomial::POLYERROR error){
        if(error ==Polynomial::NEGATIVE_DEGREE){
            cerr<<"You inserted a negative degree!"<<endl;
        }
        else
            cerr<<"Unexpected Error. Running diagnostics.."<<endl;
    }

}
void Menu::evaluateMenu()
{
    try{
    Polynomial p1;
    p1.input();
    float x;
    cout<<"Please input your variable: "<<endl;
    cin>> x;
    cout<<"The value of your Polynomial is : "<<p1.evaluate(x)<<endl;
    }catch(Polynomial::POLYERROR error){
        if(error == Polynomial::NEGATIVE_DEGREE)
            cerr<<"You inserted a negative degree!"<<endl;

    else
        cerr<<"Unexpected Error. Running diagnostics.."<<endl;
        }
}
