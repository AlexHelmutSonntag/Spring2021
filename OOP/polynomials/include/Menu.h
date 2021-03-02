#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "Polynomial.h"
#include<vector>
class Menu
{
    public:
    enum EvaluationError{WRONG_INPUT};

        Menu() {};
        void run();
    private:
        int printMenu();
        void inputMenu();
        void addMenu();
        void subtractMenu();
        void multiplyMenu();
        void evaluateMenu();
        void print();
        std::vector<Polynomial> database;


};

#endif // MENU_H_INCLUDED
