#include "widget.hpp"

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
void Widget::cmdwn(genv::event ev){
    if(ev.type==genv::ev_mouse&&ev.button==1&&onhover){
        mousedown=true;
    }else{
        mousedown=false;
    }
}
