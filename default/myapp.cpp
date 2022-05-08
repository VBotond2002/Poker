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
    Profile* _p1=new Profile(_W/2-deck[0]->getw(),_H-deck[0]->geth(),deck[0]->getw()*2,deck[0]->geth()/2);
    p1=_p1;
    release_hand();
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
    clear_table();
    clear_hand();
    release_hand();
    if(is_released_hand()){
        release_flop();
        release_turn();
        release_river();
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
    for(size_t i=0;i<table.size();i++){
        table[i]->show();
    }
    gout<<refresh;
}

void MyApp::apploop(){
    event ev;
    gin.timer(1000/60);
    while(gin>>ev){
        if(ev.type==ev_mouse||ev.type==ev_key)handle(ev);
        else if(ev.type==ev_timer){
            update();
            show();
        }

    }
}
void MyApp::bet_by_player(Profile* a,usi b){
    a->change_money(-b);
    TABLE_MONEY+=b;
}
Card* MyApp::pick_random_card(){
    srand(time(NULL));
    if(p1->getcard1()!=nullptr&&p1->getcard2()!=nullptr){
    while(true){
        usi random=rand()%52;
        Card* curr=deck[random];
        if(curr!=p1->getcard1()&&curr!=p1->getcard2()){
            usi counter=0;
            for(size_t i=0;i<table.size();i++){
                if((table[i]==curr)==false){
                    counter++;
                }
            }
            if(counter==table.size()){
                return curr;
            }
        }
    }
    }if(p1->getcard1()!=nullptr&&p1->getcard2()==nullptr){
        while(true){
            usi random=rand()%52;
            Card* curr=deck[random];
            if(curr!=p1->getcard1()){
                return curr;
            }
        }
    }
    if(p1->getcard1()==nullptr&&p1->getcard2()==nullptr){
            usi random=rand()%52;
            Card* curr=deck[random];
            return curr;
    }

return nullptr;
}
void MyApp::release_hand(){
    Card* asd=pick_random_card();
    p1->setcard1(asd);
    Card* asd2=pick_random_card();
    p1->setcard2(asd2);
}
void MyApp::release_flop(){
    Card* t1=pick_random_card();
    t1->setxy(_W/2-t1->getw()*3,_H/2-t1->geth()/2);
    table.push_back(t1);
    Card* t2=pick_random_card();
    t2->setxy(t1->getx()+t1->getw(),t1->gety());
    table.push_back(t2);
    Card* t3=pick_random_card();
    t3->setxy(t2->getx()+t2->getw(),t2->gety());
    table.push_back(t3);
}
void MyApp::release_turn(){
    Card* t4=pick_random_card();
    t4->setxy(table[2]->getx()+table[2]->getw(),table[2]->gety());
    table.push_back(t4);
}
void MyApp::release_river(){
    Card* t5=pick_random_card();
    t5->setxy(table[3]->getx()+table[3]->getw(),table[3]->gety());
    table.push_back(t5);
}
bool MyApp::is_released_hand(){
    return p1->getcard1()!=nullptr&&p1->getcard2()!=nullptr;
}
void MyApp::clear_hand(){
    p1->clear_hand();
}
void MyApp::clear_table(){
    table.clear();
}
