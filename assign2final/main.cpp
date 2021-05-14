#include <iostream>
#include "enor.h"

using namespace std;

bool emptyFile(const string &fileName)
{


    EnorSingle t(fileName);

    t.first();

    if (t.end())
    {

        return true;
    }
    return false;
}
bool noneCaught(const string &fileName, Angler &an)
{
    EnorSingle t(fileName);

    for (t.first(); !t.end(); t.next())
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

bool maxFish(const string &fileName, Contest &c)
{
    EnorGrp t(fileName);


    int max = 0;

    for (t.first(); !t.end(); t.next())
    {

        if (t.current().sum > max)
        {
            max = t.current().sum;

            c = t.current();
        }
    }


    return true;
}


#define NORMAL_MODE
#ifdef NORMAL_MODE2

int main()
{
    cout << "----- Angler Issues-----\n\n";
    string fileName = "in.txt";
    try
    {
        if (emptyFile(fileName))
        {

            cout << "Empty File!\n";
            return 1;
        }
        Angler an;

        if (noneCaught(fileName, an))
        {

            cout << "Angler's name who didn't catch any fish : " << an.name << " in Contest ID : " << an.ID << endl;
        }
        Contest c;
        if(maxFish(fileName, c))
            cout << "ID : " << c.ID << " Fish caught : " << c.sum << endl;


    }
    catch (EnorSingle::Error exp)
    {
        cout << "Wrong File Name!\n";
        return 2;
    }

    return 0;
}


#else
#define CATCH_CONFIG_MAIN
#include "catch.hpp"


TEST_CASE("first task empty file", "t0.txt") {
    Angler e;
    CHECK_FALSE(noneCaught("t0.txt", e));
}
TEST_CASE("first task 1 angler, true ", "t1.txt") {
    Angler e;
    CHECK(noneCaught("t1.txt", e));
    CHECK(e.name=="Jerry");
    CHECK(e.ID== "LAC0512");
}

TEST_CASE("first task 1 angler, false", "t2.txt")
{
    Angler e;
    CHECK_FALSE(noneCaught("t2.txt", e));
}

TEST_CASE("first task more anglers, first one meets the requirements", "t3.txt")
{
    Angler e;
    CHECK(noneCaught("t3.txt", e));
    CHECK(e.name== "Rick");
    CHECK(e.ID == "LAC0512");
}


TEST_CASE("first task more anglers, third one meets the requirements", "t4.txt") {
    Angler e;
    CHECK(noneCaught("t4.txt", e));
    CHECK(e.name=="Nick");
    CHECK(e.ID == "LAC0512");

}


TEST_CASE("first task more anglers, last one meets the requieremenets","t5.txt")
{
    Angler e;
    CHECK(noneCaught("t5.txt", e));
    CHECK(e.name=="Anna");
    CHECK(e.ID == "SHWIFTY544");
}

TEST_CASE("first task more anglers, no one meets the requirements", "t6.txt") {
    Angler e;
    CHECK_FALSE(noneCaught("t6.txt", e));
}
//Summation and Max search


TEST_CASE("second task only group meets requirement", "t8c.txt")
{
    Contest e;
    CHECK(maxFish("t8c.txt",e));
    CHECK(e.ID == "LAC0512" );
    CHECK(e.sum == 582);
}

TEST_CASE("second task first group meets requirement", "t8.txt")
{
    Contest e;
    CHECK(maxFish("t8.txt",e));
    CHECK(e.ID == "LAC0512");
    CHECK(e.sum == 582);
}


TEST_CASE("second task second group meets requirement file", "t9.txt")
{
    Contest e;
    CHECK(maxFish("t9.txt",e));
    CHECK(e.ID == "LAC0512" );
    CHECK(e.sum == 582);
}

TEST_CASE("second task Last group meets requirement file", "t10.txt")
{
    Contest e;
    CHECK(maxFish("t10.txt",e));
    CHECK(e.ID == "LAC0512");
    CHECK(e.sum == 582);
}

#endif


