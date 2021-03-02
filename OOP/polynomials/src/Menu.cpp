#include <iostream>
#include "Menu.h"
#include "Polynomial.h"
#include <sstream>
#define menuCount 4

using namespace std;

bool check(int a){return (a>=0 && a<=5);}

void Menu:: run()
{
    int v;
    do{
        v = printMenu();
        switch(v)
        {
            case 1:
                inputMenu();
                break;
            case 2:
                addMenu();
                break;
            case 3:
                subtractMenu();
                break;
            case 4:
                multiplyMenu();
                break;
            case 5:
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
    cout<<"1. Input\n";
    cout<<"2. Add\n";
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

    //read using read.hpp
    while(s<0 || s> 4);
    //response=read<int>("Choice:",errmsg,check);

    return s;
}
void Menu::inputMenu(){
    vector<double> vec1;
    int vecSize;
    cout<<"Please input the degree of your 1st polynomial: "<<endl;
    cin>>vecSize;
    for (int i = 0; i < vecSize+1; i++)
    {
        double input;
        cout<<"Please input the coefficients(Highest degree to lowest):";
        cin>>input;
        vec1.push_back(input);
    }
    Polynomial poly1(vecSize,vec1);
    database.push_back(poly1);

    vector<double> vec2;
    vecSize=0;
    cout<<"Please input the degree of your 2nd polynomial: "<<endl;
    cin>>vecSize;
    for (int i = 0; i < vecSize+1; i++)
    {
        double input;
        cout<<"Please input the coefficients(Highest degree to lowest):";
        cin>>input;
        vec2.push_back(input);
    }
    Polynomial poly2(vecSize,vec2);
    database.push_back(poly2);


}
void Menu::multiplyMenu(){
    Polynomial output = database[1].multiply(database[0]);
    output.print();
}
void Menu :: addMenu(){
    Polynomial output = database[1].add(database[0]);
    output.print();

}
void Menu :: subtractMenu(){
    Polynomial output = database[1].subtract(database[0]);
    output.print();
}
void Menu::evaluateMenu()
{
    int x;
    cout<<"Please input x: ";
    cin>>x;
    cout<<"Please choose the polynomial(1 is first you inputted,2 being 2nd inputted: ";
    int order;
    cin>>order;
    if (order ==1)
    {
    database[order].evaluate(x);
    database[order].print();
    }
    else if(order==2){

    database[0].evaluate(x);
    database[0].print();
    }
    else{
        throw WRONG_INPUT;
    }

}
