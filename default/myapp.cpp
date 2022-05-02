#include "myapp.hpp"
using namespace genv;
MyApp::MyApp(usi _W_, usi _H_):Application(_W_,_H_)
{
    setbackgroundcolor(49, 112, 24);
    gout.load_font("LiberationSans-Regular.ttf",20);
        for(int j=two;j!=ace+1;j++){
            CARDNUM temp=static_cast<CARDNUM>(j);
            deck.push_back(new Card(0,0,72,96,temp,pikes));
            deck.push_back(new Card(0,0,72,96,temp,tiles));
            deck.push_back(new Card(0,0,72,96,temp,clover));
            deck.push_back(new Card(0,0,72,96,temp,hearts));
        }

}
MyApp::~MyApp(){
    for(size_t i=0;i<deck.size();i++){
        delete deck[i];
    }
}
void MyApp::handle(event ev){

}
void MyApp::update(){

}
void MyApp::show(){
    Color *a=&background_color;
    gout<<color(a->r,a->g,a->b);
    gout<<move_to(0,0);
    gout<<box(_W,_H);
    deck[12]->show();
    gout<<refresh;
}

void MyApp::apploop(){
    event ev;
    while(gin>>ev){
        handle(ev);
        update();
        show();
    }
}
