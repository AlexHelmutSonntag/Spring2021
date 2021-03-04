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
        void addMenu();
        void subtractMenu();
        void multiplyMenu();
        void evaluateMenu();

        Polynomial output;


};

#endif // MENU_H_INCLUDED
