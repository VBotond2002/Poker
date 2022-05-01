#ifndef CARD_HPP
#define CARD_HPP
#include "object.hpp"
#include "iostream"
typedef unsigned int usi;
enum CARDNUM{
    two,//0 index
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,//13 index
};
enum CARDCOLOR{
    hearts,//kör
    tiles,//káró
    clover,//tref
    pikes//pikk
};
class Card: public Object
{
public:
    Card(usi, usi, usi, usi,CARDNUM,CARDCOLOR);
    void handle(genv::event);;
    void update();
    void show();
    CARDNUM gettype(){return type;}
    CARDCOLOR getcolor(){return ccolor;}
    virtual ~Card();
protected:
    usi x,y,w,h;
    CARDNUM type;
    CARDCOLOR ccolor;
};

#endif // CARD_HPP
