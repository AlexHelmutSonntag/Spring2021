#include "weather.h"
#include "area.h"

using namespace std;

Area::Area(const std::string &str, int num)
{
    if (num <0)
    {
        throw NEGATIVE_WATER;
    }
    _name = str;
    _amountOfWater= num;
}




//Implementation of Plain

Plain* Plain::_instance = nullptr;
Plain* Plain::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Plain();
    }
    return _instance;
}
void Plain::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}

Area* Plain::changeState()
{

    if(_amountOfWater>15)
        return new Grassland(_amountOfWater);
    return this;
}
void Plain::transmute(Weather* weather)
{
    if(weather->getType() =="Sunny")
    {
        _amountOfWater-= 3;

    }
    else if (weather->getType()=="Cloudy")
    {
        _amountOfWater-=1;

    }
    else
    {
        _amountOfWater+= 20;
        weather->setHumidity(weather->getHumidity()+5);
    }
}

//Implementation of Grassland

Grassland* Grassland::_instance = nullptr;
Grassland* Grassland::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Grassland();
    }
    return _instance;
}
void Grassland::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}
Area* Grassland::changeState()
{

    if(_amountOfWater>50)
        return new Lakes(_amountOfWater);
    else if(_amountOfWater<16)
        return new Plain(_amountOfWater);
    return this;
}

void Grassland::transmute(Weather* weather)
{
    if(weather->getType() =="Sunny")
    {
        _amountOfWater-= 6;

    }
    else if(weather->getType()=="Cloudy")
    {
        _amountOfWater-=2;

    }
    else
    {
        _amountOfWater+=15;
        weather->setHumidity(weather->getHumidity()+10);
    }
}


//Implementation of Lakes

Lakes* Lakes::_instance = nullptr;
Lakes* Lakes::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Lakes();
    }
    return _instance;
}
void Lakes::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}
Area* Lakes::changeState()
{

    if(_amountOfWater<51)
        return new Grassland();
    return this;
}

void Lakes::transmute(Weather* weather)
{
    if(weather->getType() =="Sunny")
    {
        _amountOfWater-= 10;

    }
    else if(weather->getType()=="Cloudy")
    {
        _amountOfWater-=3;

    }
    else
    {
        _amountOfWater+=20;
        weather->setHumidity(weather->getHumidity()+15);
    }
}
