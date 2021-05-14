#include "area.h"
#include "weather.h"


using namespace std;
Weather::Weather(int humidity)
{
    if(humidity>70)
    {
        weather = new Rainy();
        weather->setType("Rainy");
        weather->setHumidity(30);
    }

    else if(humidity>=40 && humidity<=70)
    {
        bool chanceOfRain=((humidity-40)*3.3>50);
        if(!chanceOfRain)
        {
            weather = new Cloudy();
            weather->setType("Cloudy");
            weather->setHumidity(humidity);
        }
        else
        {
            weather = new Rainy();
            weather->setType("Rainy");
            weather->setHumidity(humidity);
        }
    }

    else if(humidity<40)
    {
        weather = new Sunny();
        weather->setHumidity(humidity);
        weather->setType("Sunny");
    }

}

void Weather::changeWeather()
{
    Weather(humidityOfAir);
}

// implementation of class Sunny
Sunny* Sunny::_instance = nullptr;
Sunny* Sunny::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Sunny();
    }
    return _instance;
}
void Sunny::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}

// implementation of class Cloudy
Cloudy* Cloudy::_instance = nullptr;
Cloudy* Cloudy::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Cloudy();
    }
    return _instance;
}
void Cloudy::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}


// implementation of class Rainy
Rainy* Rainy::_instance = nullptr;
Rainy* Rainy::instance()
{
    if(_instance == nullptr)
    {
        _instance = new Rainy();
    }
    return _instance;
}
void Rainy::destroy()
{
    if ( nullptr!=_instance )
    {
        delete _instance;
        _instance = nullptr;
    }
}


