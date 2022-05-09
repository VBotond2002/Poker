#ifndef SLIDER_H
#define SLIDER_H

#include "widget.hpp"
#include "common.h"
#include "sbutton.hpp"
#include "mouse.hpp"
class Slider: public Widget
{
public:
    Slider(usi,usi,usi,usi);
    virtual ~Slider();
    virtual void handle(genv::event);
    virtual void update();
    virtual void show();
protected:
    SButton* bt;
    usi MONEY=0;
    usi mx,my;
    bool firstclick=false;
    Mouse mouse_tracker;
};

#endif // SLIDER_H
