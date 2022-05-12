#include "widget.hpp"
using namespace genv;
Widget::Widget(usi a, usi b, usi c, usi d)
{
x=a;
y=b;
w=c;
h=d;
}
Widget::~Widget(){

}
void Widget::conhv(usi a, usi b){
 if(a>=x&&a<=x+w&&b>=y&&b<=y+h){
     onhover=true;
 }else{
     onhover=false;
 }
}
bool Widget::isclicked(event ev){
    if(ev.type==ev_mouse&&ev.button==1&&ishover(ev)){
        return true;
    }return false;
}
bool Widget::ishover(event ev){
    if(ev.type==ev_mouse&&ev.pos_x>x&&ev.pos_x<x+w&&ev.pos_y>y&&ev.pos_y<y+h){
        return true;
    }return false;
}
void Widget::drawborder(usi a,usi b,usi c){
    gout<<color(a,b,c);
    gout<<move_to(x,y);
    gout<<line(w,0);
    gout<<line(0,h);
    gout<<line(-w,0);
    gout<<line(0,-h);
}
void Widget::cmdwn(genv::event ev){
    if(ev.type==genv::ev_mouse&&ev.button==1&&onhover){
        mousedown=true;
    }else{
        mousedown=false;
    }
}
