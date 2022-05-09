#include "sbutton.hpp"
using namespace genv;
SButton::SButton(usi a,usi b,usi c,usi d,std::string e): Button(a,b,c,d,e)
{

}
SButton::~SButton(){

}
void SButton::handle(event ev){
    conhv(ev.pos_x,ev.pos_y);
    cmdwn(ev);
}
void SButton::update(){


}
void SButton::show(){
    if(mousedown)gout<<color(hh_color.r,hh_color.g,hh_color.b);
    else gout<<color(bg_color.r,bg_color.g,bg_color.b);
    gout<<move_to(x,y);
    gout<<box(w,h);
    drawborder(0,0,0);
}

