#ifndef ENOR_H_INCLUDED
#define ENOR_H_INCLUDED

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>


struct Measurement
{
    std::string species;
    int fish_Size;
    friend std::istream&operator>>(std::istream&is,Measurement &m);

};

struct Angler
{
    std::string name;
    std::string ID;
    bool none_Caught;
    int sum=0;
    friend std::istream&operator>>(std::istream&is,Angler &a);
};

struct Contest
{
    std::string ID;
    int sum =0;
};

enum Status {norm,abnorm};


class EnorSingle{

    public :
        enum Error{FILE_ERROR};
        EnorSingle(const std::string &fileName);
        ~EnorSingle(){_x.close();}
        void first(){read();}
        void next(){read();}
        Angler current() const{return _dx;}
        bool end() const{return _sx==abnorm;}

    private:
        std::ifstream _x;
        Angler _dx;
        Status _sx;
        void read();
};

class EnorGrp{

    public:
        enum Error {FILE_ERROR};
        EnorGrp(const std::string &fileName);
        ~EnorGrp(){_x.close();}
        void first(){read(); next();}
        Contest current() const{return _curr;}
        void next();
        bool end() const{return _end;}

    private:
        std::ifstream _x;
        Angler _dx;
        Status _sx;
        Contest _curr;
        bool _end;

        void read();

};


#endif // ENOR_H_INCLUDED
