#include <iostream>
#include <algorithm>
#include <sstream>
#include "Menu.h"
#include "Polynomial.h"
#define menuCount 6

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
            case 6:
                printPolys();
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
    cout<<"3. Subtract\n";
    cout<<"4. Multiply\n";
    cout<<"5. Evaluate\n";
    cout<<"6. Print\n";
    cout<<"****************************************\n";
    //produce error message

    int s=0;
    do {

    cout<<"It has to be a number between 0 and "<<menuCount<<"!"<<endl;
    cin>>s;
    }

    //read using read.hpp
    while(s<0 || s> 6);
    //response=read<int>("Choice:",errmsg,check);

    return s;
}

void Menu::printPolys()
{   if(database.size()<=0) throw EMPTY_DATABASE;
    else
        {
            for(int i=0;i<database.size();i++)
            {
                database[i].print();
            }
        }

}
void Menu::inputMenu(){
    vector<double> vec1;
    vec1.clear();
    int degree;
    cout<<"Please input the degree of your polynomial: "<<endl;
    cin>>degree;
    vec1.resize(degree+1);
    for (int i = 0; i < degree+1; i++)
    {
        double input;
        cout<<"Please input the coefficients(Highest degree to lowest):";
        cin>>input;
        //vec1.push_back(input);
        vec1[i]=input;
    }
    Polynomial poly1(degree,vec1);
    database.push_back(poly1);
    vector<double> vec2;
    degree=0;
    cout<<"Please input the degree of your 2nd polynomial: "<<endl;
    cin>>degree;
    vec2.resize(degree+1);
    for (int i = 0; i < degree+1; i++)
    {
        double input;
        cout<<"Please input the coefficients(Highest degree to lowest):";
        cin>>input;
        //vec2.push_back(input);
        vec2[i]=input;
    }
    Polynomial poly2(degree,vec2);
    database.push_back(poly2);
    //std::reverse(database.begin(), database.end());
}
void Menu::multiplyMenu(){
    if(database.size()!=2) throw EMPTY_DATABASE;
    else{
    output = database[1].multiply(database[0]);
    output.print();
    }
}
void Menu :: addMenu(){
    if(database.size()!=2) throw EMPTY_DATABASE;
    else{
    output = database[1].add(database[0]);
    output.print();
    }
}
void Menu :: subtractMenu(){
    if(database.size()!=2) throw EMPTY_DATABASE;
    else{
    output = database[1].subtract(database[0]);
    output.print();
    }
}
void Menu::evaluateMenu()
{


    int x;
    cout<<"Please input x: ";
    cin>>x;
    cout<<"Please choose the polynomial you want to evaluate! 1 being the 1st you inputted. 2 being the 2nd you inputted >";
    int input;
    cin>>input;
    if (input ==-1)throw WRONG_INPUT;
    else{
        if(input ==1 ){
    database[0].print();
    cout<<database[0].evaluate(x);
    }

    else if(input==2){

    database[1].print();
    cout<<database[1].evaluate(x);

            }
        }

}
