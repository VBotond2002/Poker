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
    bool getonhvr(){return onhover;}
    void cmousedown(usi,usi);
    void conhover(usi,usi);
    virtual ~Widget();
protected:
usi x,y,w,h;
bool mousedown,onhover;
};

#endif // WIDGET_HPP
