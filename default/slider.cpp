#include "slider.hpp"
using namespace genv;
Slider::Slider(usi a, usi b, usi c, usi d): Widget(a,b,c,d)
{
bt=new SButton(x,y,20,20,"");
}
Slider::~Slider(){}

void Slider::handle(event ev){
    bt->handle(ev);
    conhv(ev.pos_x,ev.pos_y);
    cmdwn(ev);
}
void Slider::update(){
    bt->update();
}
void Slider::show(){
    gout<<color(105, 35, 26);
    gout<<move_to(x,y);
    gout<<box(w,h);
    drawborder(0,0,0);
    bt->show();
}
