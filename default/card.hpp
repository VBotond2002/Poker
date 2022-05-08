#ifndef CARD_HPP
#define CARD_HPP
#include "object.hpp"
#include "iostream"
#include "vector"
#include "fstream"
#include "common.h"
typedef unsigned int usi;



class Card: public Object
{
public:
    Card(usi, usi, usi, usi,CARDNUM,CARDCOLOR);
    void handle(genv::event);;
    void update();
    void show();
    CARDNUM gettype(){return type;}
    CARDCOLOR getcolor(){return ccolor;}
    void setxy(usi a ,usi b){x=a;y=b;}
    void transxy(usi a, usi b){x+=a;y+=b;};
    usi getx(){return x;}
    usi gety(){return y;}
    usi getw(){return w;}
    usi geth(){return h;}
    bool operator==(Card* c2);
    bool operator!=(Card* c2);
    virtual ~Card();
protected:
    void loadimage(std::string path);
    usi x,y,w,h;
    CARDNUM type;
    CARDCOLOR ccolor;
    std::vector<std::vector<int>> img;
};

#endif // CARD_HPP
