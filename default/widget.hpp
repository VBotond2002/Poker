#ifndef WIDGET_HPP
#define WIDGET_HPP
#include "graphics.hpp"
typedef unsigned int usi;
class Widget
{
public:
    Widget(usi,usi,usi,usi);
    virtual void handle(genv::event)=0;
    virtual void update()=0;
    virtual void show()=0;
    bool getmdwn(){return mousedown;}
    bool getonhv(){return onhover;}
    void cmdwn(genv::event);//calculate mousedown if onhover
    void conhv(usi,usi);//calculete onhover
    void drawborder(usi,usi,usi);
    virtual ~Widget();
protected:
usi x,y,w,h,POT;
bool mousedown,onhover,selected=false;
};

#endif // WIDGET_HPP
