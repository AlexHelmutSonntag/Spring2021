#include "enor.h"

std::istream&operator>>(std::istream&is,Measurement &m){

    is>> m.species >>m.fish_Size;
    return is;
}

std::istream &operator>>(std::istream&is,Angler &a)
{
    std::string line;
    getline(is,line,'\n');
    std::stringstream ss(line);
    ss>>a.name >>a.ID;
    a.none_Caught = true;
    int sumOfFish = 0;
    Measurement m;

    while(ss>>m)
    {
        a.none_Caught = a.none_Caught && (m.fish_Size<=0);
        sumOfFish+=m.fish_Size;
    }
    a.sum = sumOfFish;

    return is;

}

EnorSingle::EnorSingle(const std::string &fileName)
{
    _x.open(fileName);

    if(_x.fail()) throw FILE_ERROR;
}

void EnorSingle:: read()
{


    _sx = (_x>>_dx) ? norm : abnorm;

}

EnorGrp::EnorGrp(const std::string &fileName)
{
    _x.open(fileName);

    if(_x.fail()) throw FILE_ERROR;
}

void EnorGrp :: read()
{
    _sx = (_x>>_dx)? norm: abnorm;
}

void EnorGrp:: next()
{
    _end = (_sx == abnorm);
    if(!_end)
    {

        int sumGrp = 0;
        _curr.ID = _dx.ID;
        for(;_sx==norm&& _curr.ID == _dx.ID;read())
        {
            sumGrp+=_dx.sum;

        }
        _curr.sum = sumGrp;
    }
}







