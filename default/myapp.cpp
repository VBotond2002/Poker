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
        TABLE_MONEY=0;
    Profile* p1=new Profile(_W/2-deck[0]->getw(),_H-deck[0]->geth(),deck[0]->getw()*2,deck[0]->geth()/2);
    p1->setcards(deck[48],deck[49]);
    Button* bt1=new Button(_W/2+deck[0]->getw(),_H-deck[0]->geth()/2,100,deck[0]->geth()/2,"Bet");
    Button* bt2=new Button(_W/2+deck[0]->getw()+100,_H-deck[0]->geth()/2,100,deck[0]->geth()/2,"Check");
    Button* bt3=new Button(_W/2+deck[0]->getw()+200,_H-deck[0]->geth()/2,100,deck[0]->geth()/2,"Raise");
    bt1->setclick_action([](){std::cout<<"bt1 clicked";});
    widgets.push_back(p1);
    widgets.push_back(bt1);
    widgets.push_back(bt2);
    widgets.push_back(bt3);
}
MyApp::~MyApp(){
    for(size_t i=0;i<deck.size();i++){
        delete deck[i];
    }for(size_t i=0;i<widgets.size();i++){
        delete widgets[i];
    }
}
void MyApp::handle(event ev){
    for(size_t i=0;i<widgets.size();i++){
        widgets[i]->handle(ev);
    }
}
void MyApp::update(){
    for(size_t i=0;i<widgets.size();i++){
        widgets[i]->update();
    }
}
void MyApp::show(){
    Color *a=&background_color;
    gout<<color(a->r,a->g,a->b);
    gout<<move_to(0,0);
    gout<<box(_W,_H);
    for(size_t i=0;i<widgets.size();i++){
        widgets[i]->show();
    }
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
void MyApp::bet_by_player(Profile* a,usi b){
    a->change_money(-b);
    TABLE_MONEY+=b;
}
