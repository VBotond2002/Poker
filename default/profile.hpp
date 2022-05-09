#ifndef PROFILE_HPP
#define PROFILE_HPP
#include "widget.hpp"
#include "common.h"
#include "card.hpp"
class Profile: public Widget
{
public:
    Profile(usi,usi,usi,usi);
    virtual void handle(genv::event);
    virtual void update();
    virtual void show();
    void change_money(int a);
    void setbase_color(usi,usi,usi);
    void sethh_color(usi,usi,usi);
    void setcards(Card* a,Card* b);
    void setcard1(Card*a);
    void setcard2(Card*a);
    void clear_hand(){CARD1=nullptr;CARD2=nullptr;}
    Card* getcard1(){return CARD1;};
    Card* getcard2(){return CARD2;}
    virtual ~Profile();
protected:
    usi MONEY;
    Card *CARD1=nullptr,*CARD2=nullptr;
    Color base_color,hh_color;//hh=highlight
};

#endif // PROFILE_HPP
