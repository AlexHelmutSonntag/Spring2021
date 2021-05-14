#ifndef AREA_H_INCLUDED
#define AREA_H_INCLUDED


#include<string>
#include"weather.h"
class Area
{
protected:
    std::string _name;
    int _amountOfWater;
    Area() {}
    Area (const std::string &str, int num);
public:

    enum Exception {NEGATIVE_WATER};

    //getters
    std::string name() const
    {
        return _name;
    }
    int getWater ()
    {
        return _amountOfWater;
    }


    bool negativeWater() const
    {
        return (_amountOfWater < 0);
    }

    //setters
    void setWater(int num)
    {
        _amountOfWater = num;
    }
    void setName (string name)
    {
        _name = name;
    }


    virtual void transmute(Weather *weather) = 0;
    virtual Area* changeState()=0;
    virtual ~Area () {}

};

// class of Plain
class Plain : public Area
{
public:
    static Plain* instance();
    static void destroy() ;
    Plain() {}


    Plain(int num ) : Area("P", num) {}

    Area* changeState() override;
    void transmute(Weather* weather) override;
private:
    static Plain* _instance;
};

// class of Grassland
class Grassland : public Area
{
public:
    static Grassland* instance();
    static void destroy() ;
    Grassland() {}
    Grassland(int num ) : Area("G", num) {}

    Area* changeState() override;
    void transmute(Weather* weather) override ;
private:
    static Grassland* _instance;
};

// class of Lakes
class Lakes : public Area
{
public:
    static Lakes* instance();
    static void destroy() ;
    Lakes() {}
    Lakes(int num ) : Area("L", num) {}
    Area* changeState() override;


    void transmute(Weather* weather) override ;


private:
    static Lakes* _instance;
};





#endif // AREA_H_INCLUDED
