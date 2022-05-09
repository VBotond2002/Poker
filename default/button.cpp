#include "button.hpp"
using namespace genv;
Button::Button(usi a,usi b,usi c,usi d,std::string s):Widget(a,b,c,d)
{
txt=s;
}
Button::~Button(){};
void Button::setclick_action(std::function<void()> f){
     click_action=f;
}
void Button::handle(genv::event ev){
    conhv(ev.pos_x,ev.pos_y);
    cmdwn(ev);
}
void Button::update(){
    if(mousedown){
        click_action();

    }
}
void Button::show(){
    if(mousedown)gout<<color(150, 46, 33);
    else gout<<color(105, 35, 26);
    gout<<move_to(x,y);
    gout<<box(w,h);
    gout<<color(0,0,0);
    gout<<move_to(x+w/2-gout.twidth(txt)/2,y+h/2-gout.cascent()+gout.cdescent());
    gout<<text(txt);
    drawborder(0,0,0);
}

