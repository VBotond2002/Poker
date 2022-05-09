#ifndef MOUSE_HPP
#define MOUSE_HPP
#include "graphics.hpp"
#include "common.h"
class Mouse
{
public:
    Mouse();
    virtual ~Mouse();
    void set_if_action(std::function<bool()>);
     void set_if_action_2(std::function<bool()>);
    void track_if_action_m(genv::event);
    void track_if_action_m2(genv::event);
    bool mouse_moved();
    int x_diff();
    int y_diff();
    void handle(genv::event);
    void update(genv::event);
    void show();
protected:
    usi mx=0,my=0,m2x=0,m2y=0;
    std::function<bool()> if_action=NULL,if_action_2=[this](){return mouse_moved();};
};

#endif // MOUSE_HPP
