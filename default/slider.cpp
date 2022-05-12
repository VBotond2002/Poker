#include "slider.hpp"
using namespace genv;
Slider::Slider(usi a, usi b, usi c, usi d): Widget(a,b,c,d)
{
bt=new SButton(x,y,20,20,"");
initial_money=bt->getx();
}
Slider::~Slider(){}

void Slider::cmouse2(event ev){
    if(ev.type==ev_mouse){
        m2x=ev.pos_x;
        m2y=ev.pos_y;
    }
}
void Slider::handle(event ev){
    bt->handle(ev);
    conhv(ev.pos_x,ev.pos_y);
    cmdwn(ev);
    if(bt->isclicked(ev)&&firstclick==false){
        firstclick=true;
        mx=ev.pos_x;
    }
    if(firstclick){
       cmouse2(ev);
       if(bt->getx()+m2x-mx>=x&&bt->getx()+bt->getw()+m2x-mx<=x+w){
        bt->transx(m2x-mx);
       }
       mx=ev.pos_x;
        bt->setmdwn(true);
      if(ev.type==ev_mouse&&ev.button==-1)bt->setmdwn(false);
    }if(!bt->getmdwn()){
        firstclick=false;
    }
}
void Slider::update(){
    bt->update();
    MONEY=user_money-(user_money-(bt->getx()-initial_money));
    if(MONEY>user_money){
        MONEY-=MONEY-user_money;
    }

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
