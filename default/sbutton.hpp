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
    void setx(usi a){x=a;};
    void sety(usi a){y=a;};
    void transx(usi a){x+=a;};
    void transy(usi a){y+=a;}
    void setmdwn(bool a){mousedown=a;}
    virtual ~SButton();
protected:
    Color bg_color={105, 35, 26},hh_color={150, 46, 33};
};

#endif // SBUTTON_HPP
