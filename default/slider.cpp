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
    if(bt->getmdwn())firstclick=true;
    else firstclick=false;
    mouse_tracker.set_if_action([this](){return firstclick;});
    mouse_tracker.track_if_action_m(ev);

    mouse_tracker.track_if_action_m2(ev);
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
    std::stringstream ss;
    ss<<MONEY;
    std::string out;
    ss>>out;
    gout<<move_to(x+w/2-gout.twidth(out),y-gout.cascent());
    gout<<text(out);
}
