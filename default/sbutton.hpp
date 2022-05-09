#ifndef SBUTTON_HPP
#define SBUTTON_HPP
#include "button.hpp"
#include "common.h"


class SButton: public Button
{
public:
    SButton(usi,usi,usi,usi,std::string);
    void handle(genv::event);
    void update();
    void show();
    virtual ~SButton();
};

#endif // SBUTTON_HPP
