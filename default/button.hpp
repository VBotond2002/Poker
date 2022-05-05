#ifndef BUTTON_HPP
#define BUTTON_HPP
#include "common.h"
#include "widget.hpp"


class Button
{
public:
    Button(usi,usi,usi,usi,std::string);
    virtual ~Button();
protected:
    std::string txt;
    std::function<void()> action();
};

#endif // BUTTON_HPP
