#include "card.hpp"
using namespace genv;
Card::Card(usi a, usi b, usi c, usi d,CARDNUM e,CARDCOLOR col): Object(a,b,c,d)
{
    type=e;
    ccolor=col;
    x=a;
    y=b;
    w=c;
    h=d;
}
void Card::handle(event ev){

}
void Card::update(){

}
void Card::show(){
    gout<<color(255,255,255);
    gout<<move_to(x,y);
    gout<<box(w,h);
}
Card::~Card(){

}
