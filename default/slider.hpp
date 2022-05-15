#ifndef SLIDER_H
#define SLIDER_H

#include "widget.hpp"
#include "common.h"
#include "sbutton.hpp"
#include "math.h"
class Slider: public Widget
{
public:
    Slider(usi,usi,usi,usi);
    virtual ~Slider();
    virtual void handle(genv::event);
    virtual void update();
    virtual void show();
    void setusermoney(usi a){user_money=a;};
    inline usi getmoney(){return MONEY;};
    void cmouse2(genv::event);
protected:
    SButton* bt;
    usi MONEY=0,user_money,initial_money;
    usi mx,my,m2x,m2y;
    bool firstclick=false;

};

#endif // SLIDER_H
