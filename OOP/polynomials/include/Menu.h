#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Polynomial.h"
#include<vector>
class Menu
{
    public:
    enum MENU_HANDLING_ERROR{WRONG_INPUT,EMPTY_DATABASE};

        Menu() {};
        void run();
    private:
        int printMenu();
        void inputMenu();
        void printPolys();
        void addMenu();
        void subtractMenu();
        void multiplyMenu();
        void evaluateMenu();
        void print();
        std::vector<Polynomial> database;
        Polynomial output;


};

#endif // MENU_H_INCLUDED
