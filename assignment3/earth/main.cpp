//Author:        Aly Elalwany
//Date:          02.05.2021
//Title          Simulation rounds for weather changes

using namespace std;
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "area.h"
#include "weather.h"
struct Owner
{
    string title;
    string name;
    Area* area;
    int amountOfWater;
};

void create(const string &str, vector<Area*> &areas,vector<Owner> &owners,int & humidity)
{
    ifstream f(str);
    if(f.fail())
    {
        cout << "Wrong file name!\n";
        exit(1);
    }

    // population of the areas
    int n;
    f >> n;
    if(n<0)
    {
        throw(n);
    }
    areas.resize(n);
    for( int i=0; i<n; ++i )
    {

        try
        {
            Owner owner;
            string title;
            string name;
            char ch;

            f >>owner.title >> owner.name >>ch >> owner.amountOfWater;
            switch(ch)
            {
            case 'P' :
                owner.area = new Plain( owner.amountOfWater);
                break;
            case 'G' :
                owner.area  = new Grassland(owner.amountOfWater);
                break;
            case 'L' :
                owner.area  = new Lakes(owner.amountOfWater);
                break;
            }

            owners.push_back(owner);
        }
        catch(Area::Exception msg)
        {
            cout << "Negative amount of water detected!" << endl;
            exit(1);
        }
    }
    f>>humidity;
}


bool simulation(vector<Owner> &owners, int &humidity)
{
    Weather temp(humidity);
    Weather* temp_ptr = temp.weather;

    for(int i =0; i<10; i++)
    {
        cout<<endl<<"Round #" << i+1<<endl;

        for(unsigned int j=0; j<owners.size(); ++j)
        {

            owners[j].area->transmute(temp_ptr);

            if(owners[j].area->getWater()>=0)
            {
                owners[j].area = owners[j].area->changeState();
                cout<<owners[j].title<<" "<<owners[j].name<<" " << owners[j].area->name()<<" "<<owners[j].area->getWater()<<endl;
            }
            else
            {
                cout<< "Negative Water!\n";
                return false;
            }

        }
        temp_ptr->changeWeather();
    }
    return true;
}
Owner maxAmountWater(vector<Owner> &owners)
{
    Owner winner;
    winner.amountOfWater= owners[0].area->getWater();
    winner.name= owners[0].name;
    for(Owner current : owners)
    {
        if(current.area->getWater()>winner.amountOfWater)
        {
            winner.amountOfWater = current.area->getWater();
            winner = current;
        }
    }
    cout<<"\nOwner with max water : " <<winner.title<<" "<<winner.name << " || amount of water : " <<winner.amountOfWater<<endl;
    return winner;

}
bool destroy(vector<Area*> &areas)
{
    for(int i=0; i<(int)areas.size(); ++i) delete areas[i];

    return true;
}
//#define NORMAL_MODE
#ifdef NORMAL_MODE
int main()
{

    cout<<"------------------Mother Earth------------------"<<endl;
    vector<Area*> areas;
    vector<Owner> owners;
    Owner winner;
    string filename = "in1.txt";
    int humidity;
    create(filename,areas,owners,humidity);

    if(simulation(owners,humidity))
    {
        winner = maxAmountWater(owners);
    }

    //This is optional as it's language dependent.
    if(destroy(areas))
        cout<<"\nDestroyed the vector"<<endl;


    return 0;
}

#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

//Creation tests
TEST_CASE("EmptyFile//No owners","int1.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    create("int1.txt",areas,owners,humidity);
    CHECK(owners.size()==0);

}

TEST_CASE("One Owner","int2.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    create("int2.txt",areas,owners,humidity);
    CHECK(owners.size()==1);

}
TEST_CASE("Two Owners","int3.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    create("int3.txt",areas,owners,humidity);
    CHECK(owners.size()==2);

}

TEST_CASE("More than 2 Owners","in1.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    create("in1.txt",areas,owners,humidity);
    CHECK(owners.size()==4);
}

// Checking Negative Water

TEST_CASE("Negative water check","int4.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    Owner winner;
    create("int4.txt",areas,owners,humidity);
    CHECK(owners.size()==1);
    bool negativeWater= simulation(owners,humidity);

    CHECK(negativeWater);
}


// Checking winners
TEST_CASE("1 Owner ","int5.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    Owner winner;
    create("int5.txt",areas,owners,humidity);
    CHECK(owners.size()==1);
    simulation(owners,humidity);
    winner = maxAmountWater(owners);
    CHECK(winner.name == "Bean");
}

TEST_CASE("2 Owners","int6.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    Owner winner;
    create("int6.txt",areas,owners,humidity);
    CHECK(owners.size()==2);
    simulation(owners,humidity);
    winner = maxAmountWater(owners);
    CHECK(winner.name == "Bean");
}
TEST_CASE("3 Owners","int7.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    Owner winner;
    create("int7.txt",areas,owners,humidity);
    CHECK(owners.size()==3);
    simulation(owners,humidity);
    winner = maxAmountWater(owners);
    CHECK(winner.name == "Bean");
}
TEST_CASE("4 Owners","in1.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    Owner winner;
    create("in1.txt",areas,owners,humidity);
    CHECK(owners.size()==4);
    simulation(owners,humidity);
    winner = maxAmountWater(owners);
    CHECK(winner.name == "Bean");
}

// Checking Wrong number of lines
TEST_CASE("4 Owners, wrong number of lines(3) ","int8.txt")
{
    vector<Area*> areas;
    vector<Owner> owners;
    int humidity;
    int maxWater;
    Owner winner;
    create("int8.txt",areas,owners,humidity);
    CHECK_FALSE(owners.size()==4);
}
#endif // NORMAL_MODE
