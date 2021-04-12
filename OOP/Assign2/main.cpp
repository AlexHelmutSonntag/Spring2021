#include <iostream>
#include "enor.h"
using namespace std;

bool emptyFile(const string &fileName){

    EnorSingle t (fileName);

    t.first();

    if(t.end())
    {

        return true;
    }
    return false;
}
bool noneCaught(const string &fileName,Angler & an)
{
    EnorSingle t(fileName);

    for(t.first();!t.end();t.next())
    {
        if (t.current().none_Caught)
        {
            an.ID = t.current().ID;
            an.name = t.current().name;
            return true;
        }

    }
    return false;

}

void maxFish(const string&fileName,Contest &c)
{
    EnorGrp t(fileName);
    int max=0;

    for(t.first();!t.end();t.next())
    {

        if(t.current().sum>max)
        {
            max = t.current().sum;

            c = t.current();
        }
    }

    cout<<"ID : "<<c.ID<<" Fish caught : "<<c.sum<<endl;
}

int main()
{
    cout<< "----- Angler Issues-----\n\n";
    string fileName = "in.txt";
    try{
        if(emptyFile(fileName))
        {

            cout<<"Empty File!\n";
            return 1;
        }
        Angler an;

        if(noneCaught(fileName,an))
        {

            cout<<"Angler's name who didn't catch any fish : " << an.name << " in Contest ID : "<<an.ID<<endl;
        }
        Contest c;
        maxFish(fileName,c);



    }catch (EnorSingle::Error exp)
    {
    cout<< "Wrong File Name!\n";
    return 2;
    }

    return 0;
}
