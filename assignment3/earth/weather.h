#ifndef WEATHER_H_INCLUDED
#define WEATHER_H_INCLUDED

#include <string>
using namespace std;
class Plain;
class Grassland;
class Lakes;
class Area;

// class of the abstract weathers
class Weather
{
protected:
    string typeOfWeather;
    int humidityOfAir;
public:

    Weather() {}
    Weather(int humidity);
    Weather *weather; //Pointer to the current weather

    virtual ~Weather() {}
    string getType()
    {
        return typeOfWeather;
    }
    void changeWeather();
    int getHumidity ()
    {
        return humidityOfAir;
    }
    void setType(string type)
    {
        typeOfWeather = type;
    }
    void setHumidity(int hum)
    {
        humidityOfAir = hum;
    }



};

// class of Sunny
class Sunny : public Weather
{
public:
    Sunny() {}
    static Sunny* instance();
    static void destroy() ;

private:
    static Sunny* _instance;
};

// class of Cloudy
class Cloudy : public Weather
{
public:
    Cloudy() {}
    static Cloudy* instance();
    static void destroy();

private:
    static Cloudy* _instance;
};

// class of Rainy
class Rainy : public Weather
{
public:

    Rainy() {}
    static Rainy* instance();
    static void destroy() ;

private:
    static Rainy* _instance;
};

#endif // WEATHER_H_INCLUDED
