#ifndef CARD_HPP
#define CARD_HPP
#include "object.hpp"
typedef unsigned int usi;
class Card: public Object
{
public:
    Card(usi, usi, usi, usi);
    void handle(genv::event);;
    void update();
    void show();
    virtual ~Card();
protected:
    usi x,y,w,h;
};

#endif // CARD_HPP
