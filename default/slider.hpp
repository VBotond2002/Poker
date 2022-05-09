#ifndef SLIDER_H
#define SLIDER_H

#include "widget.hpp"
#include "common.h"
#include "sbutton.hpp"
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
};

#endif // SLIDER_H
