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
    gout<<color(0,0,0);
    gout<<move_to(x,y);
    gout<<line_to(x+w,y);
    gout<<line_to(x+w,y+h);
    gout<<line_to(x,y+h);
    gout<<line_to(x,y);
    gout<<move_to(x,y);
   switch(ccolor){
   case hearts:
       gout<<color(255,0,0);
       break;//kör
    case tiles:
       gout<<color(255,0,0);
       break;//káró
   case clover:
       gout<<color(0,0,0);
       break;//tref
   case pikes:
       gout<<color(0,0,0);
       break;//pikk
   }
    switch(type){
        case two:
           gout<<move(gout.twidth("2")/2,0);
           gout<<text("2");
        break;
    case three:
        gout<<move(gout.twidth("3")/2,0);
        gout<<text("3");
         break;
    case four:
        gout<<move(gout.twidth("4")/2,0);
        gout<<text("4");
         break;
    case five:
        gout<<move(gout.twidth("5")/2,0);
        gout<<text("5");
         break;
    case six:
        gout<<move(gout.twidth("6")/2,0);
        gout<<text("6");
         break;
    case seven:
        gout<<move(gout.twidth("7")/2,0);
        gout<<text("7");
         break;
    case eight:
        gout<<move(gout.twidth("8")/2,0);
        gout<<text("8");
         break;
    case nine:
        gout<<move(gout.twidth("9")/2,0);
        gout<<text("9");
         break;
    case ten:
        gout<<move(1,0);
        gout<<text("10");
         break;
    case jack:
        gout<<move(gout.twidth("J")/2,0);
        gout<<text("J");
         break;
    case queen:
        gout<<move(gout.twidth("Q")/3,0);
        gout<<text("Q");
         break;
    case king:
        gout<<move(gout.twidth("K")/3,0);
        gout<<text("K");
         break;
    case ace:
        gout<<move(gout.twidth("A")/3,0);
        gout<<text("A");
         break;
    }
}
Card::~Card(){

}
