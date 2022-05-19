#include "profile.hpp"
using namespace genv;
Profile::Profile(usi a,usi b,usi c,usi d): Widget(a,b,c,d)
{
    setbase_color(50,50,50);
    MONEY=100;
}
void Profile::setbase_color(usi a, usi b, usi c){
    base_color.r=a;
    base_color.g=b;
    base_color.b=c;
}
void Profile::sethh_color(usi a, usi b, usi c){
    hh_color.r=a;
    hh_color.g=b;
    hh_color.b=c;
}
void Profile::setcards(Card* a, Card* b){
    CARD1=a;
    CARD2=b;
    CARD1->setxy(x,y-(CARD1->geth()/2));
    CARD2->setxy(x+CARD1->getw(),y-(CARD2->geth()/2));
}
void Profile::handle(genv::event){

}
void Profile::update(){

}
void Profile::show(){
    if(CARD1!=nullptr&&CARD2!=nullptr){
        CARD1->show();
        CARD2->show();
    }

    if(selected)gout<<color(hh_color.r,hh_color.g,hh_color.b);
    else gout<<color(base_color.r,base_color.g,base_color.b);
    gout<<move_to(x,y);
    gout<<box(w,h);
    std::string converted_money=convts<usi>(MONEY);
    converted_money+='$';
    gout<<color(255,255,255);
    gout<<move_to(x+w/2-gout.twidth(converted_money)/2,y+h/2-gout.cascent()+gout.cdescent());
    gout<<text(converted_money);
    drawborder(255,255,255);
}
Profile::~Profile(){}
void Profile::setcard1(Card*a){
    CARD1=a;
    CARD1->setxy(x,y-(CARD1->geth()/2));
}
void Profile::setcard2(Card*a){
    CARD2=a;
    CARD2->setxy(x+CARD1->getw(),y-(CARD2->geth()/2));
}
void Profile::change_money(int a){
    if(a<0){
        if((usi)abs(a)<=MONEY)MONEY+=a;
        else MONEY=0;
    }
   else MONEY+=a;
}
