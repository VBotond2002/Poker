#ifndef PROFILE_HPP
#define PROFILE_HPP
#include "widget.hpp"
#include "common.h"
class Profile: public Widget
{
public:
    Profile(usi,usi,usi,usi);
    virtual void handle(genv::event);
    virtual void update();
    virtual void show();
    void change_money(int a){MONEY+=a;};
    void setbase_color(usi,usi,usi);
     void sethh_color(usi,usi,usi);
    virtual ~Profile();
protected:
    usi MONEY;
    Color base_color,hh_color;//hh=highlight
};

#endif // PROFILE_HPP
