#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "widget.hpp"
#include "common.h"

class Button : public Widget
{

public:
    Button(usi,usi,usi,usi,std::string);
    void setclick_action(std::function<void()>);
    virtual void handle(genv::event);
    virtual void update();
    virtual void show();
    virtual ~Button();
protected:
    std::string txt;
    std::function<void()> click_action=NULL;
};

#endif // BUTTON_HPP
