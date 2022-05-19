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

    Button* bt1=new Button(_W/2+deck[0]->getw(),_H-deck[0]->geth()/2,100,deck[0]->geth()/2,"Bet");
    Button* bt2=new Button(_W/2+deck[0]->getw()+100,_H-deck[0]->geth()/2,100,deck[0]->geth()/2,"Next");
   // Button* bt3=new Button(_W/2+deck[0]->getw()+200,_H-deck[0]->geth()/2,100,deck[0]->geth()/2,"Raise");
    bt2->setclick_action([this](){next_phase();});
    bt1->setclick_action([this](){bet_by_player();});
    sl1=new Slider(bt1->getx(),bt1->gety()-20,bt1->getw()*3,20);
    sl1->setusermoney(p1->getmoney());
    widgets.push_back(p1);
    widgets.push_back(bt1);
    widgets.push_back(bt2);
    //widgets.push_back(bt3);
    widgets.push_back(sl1);


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
void MyApp::next_phase(){
    int i=current_phase;
    i++;
    if(i<=4){
        current_phase=static_cast<PHASE>(i);
    }else if(i>4){
        current_phase=static_cast<PHASE>(0);
    }
    action_performed=true;
}
void MyApp::update(){
    for(size_t i=0;i<widgets.size();i++){
        widgets[i]->update();
    }
    if(action_performed){
    switch(current_phase){
        case BEFORE_FLOP:

        release_hand();
        action_performed=false;
        break;
    case FLOP:
        release_flop();
        action_performed=false;
        break;
    case TURN:
        release_turn();
        action_performed=false;
        break;
    case RIVER:
        release_river();
        action_performed=false;
        break;
    case PAY:
        pay();
        clear_hand();
        clear_table();
        TABLE_MONEY=0;
        action_performed=false;

        break;
    }
    }


}
bool MyApp::search_pair(){
    std::vector<Card*> all;
    all.push_back(p1->getcard1());
    all.push_back(p1->getcard2());
    all.insert(all.end(),table.begin(),table.end());
    int c=0;
    CARDNUM lasttype;
    for(size_t i=0;i<all.size();i++){
        for(size_t j=i+1;j<all.size()-1;j++){
            if(c!=0){
                 if(all[i]->gettype()==all[j]->gettype()&&lasttype==all[i]->gettype()){
                    c++;
                    lasttype=all[i]->gettype();
                }
            }
           else if(all[i]->gettype()==all[j]->gettype()){
               c++;
               lasttype=all[i]->gettype();
           }
        }
    }if(c==1)return true;
    return false;
}
bool MyApp::search_drill(){
    std::vector<Card*> all;
    all.push_back(p1->getcard1());
    all.push_back(p1->getcard2());
    all.insert(all.end(),table.begin(),table.end());
    int c=0;
    CARDNUM lasttype;
    for(size_t i=0;i<all.size();i++){
        for(size_t j=i+1;j<all.size()-1;j++){
            if(c!=0){
                 if(all[i]->gettype()==all[j]->gettype()&&lasttype==all[i]->gettype()){
                    c++;
                    lasttype=all[i]->gettype();
                }
            }
           else if(all[i]->gettype()==all[j]->gettype()){
               c++;
               lasttype=all[i]->gettype();
           }
        }
    }if(c==2)return true;
    return false;
}bool MyApp::search_poker(){
    std::vector<Card*> all;
    all.push_back(p1->getcard1());
    all.push_back(p1->getcard2());
    all.insert(all.end(),table.begin(),table.end());
    int c=0;
    CARDNUM lasttype;
    for(size_t i=0;i<all.size();i++){
        for(size_t j=i+1;j<all.size()-1;j++){
            if(c!=0){
                 if(all[i]->gettype()==all[j]->gettype()&&lasttype==all[i]->gettype()){
                    c++;
                    lasttype=all[i]->gettype();
                }
            }
           else if(all[i]->gettype()==all[j]->gettype()){
               c++;
               lasttype=static_cast<CARDNUM>(all[i]->gettype());
           }
        }
    }if(c==3)return true;
    return false;
}bool MyApp::search_flush(){
    std::vector<Card*> all;
    all.push_back(p1->getcard1());
    all.push_back(p1->getcard2());
    all.insert(all.end(),table.begin(),table.end());
    int c=0;
    for(size_t i=0;i<all.size();i++){
        for(size_t j=i+1;j<all.size()-1;j++){
           if(all[i]->getcolor()==all[j]->getcolor()){
               c++;
           }
        }
    }if(c==4)return true;
    return false;
}
bool MyApp::search_row(){
    std::vector<Card*> all;
    all.push_back(p1->getcard1());
    all.push_back(p1->getcard2());
    all.insert(all.end(),table.begin(),table.end());
    std::vector<usi> values;
    for(size_t i=0;i<all.size();i++){
       usi val=all[i]->gettype();
       values.push_back(val);
    }
    std::sort(values.begin(),values.end());
    for(size_t i=0;i<values.size()-1;i++){
        if(values[i]+1!=values[i+1]){
            return false;
        }
    }
    return true;
}
void MyApp::pay(){
    std::cout<<"before payment:"<<p1->getmoney()<<std::endl;
    if(search_poker()){
        p1->change_money(TABLE_MONEY*5);
        sl1->setusermoney(p1->getmoney());
        std::cout<<"poker found ";
    }else if(search_row()){
        p1->change_money(TABLE_MONEY*4);
        sl1->setusermoney(p1->getmoney());
        std::cout<<"row found ";
    }else if(search_flush()){
        p1->change_money(TABLE_MONEY*3);
        sl1->setusermoney(p1->getmoney());
        std::cout<<"flush found ";
    }else if(search_drill()){
        p1->change_money(TABLE_MONEY*2);
        sl1->setusermoney(p1->getmoney());
        std::cout<<"drill found ";
    }else if(search_pair()){
        p1->change_money(TABLE_MONEY*1);
        sl1->setusermoney(p1->getmoney());
        std::cout<<"pair found ";
    }
    std::cout<<"after payment:"<<p1->getmoney()<<std::endl;
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
    std::string converted_money=convts<usi>(TABLE_MONEY);
    converted_money+='$';
    int x1=p1->getx();
    int y1=p1->gety();
    int w1=p1->getw();
    int h1=p1->geth();
    gout<<move_to(x1+w1/2-gout.twidth(converted_money)/2,y1-h1*2);
    gout<<color(0,0,0);
    gout<<text(converted_money);
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
void MyApp::bet_by_player(){
    usi b=sl1->getmoney();
    if(p1->getmoney()-b>=0){
        p1->change_money(-b);
        sl1->setusermoney(p1->getmoney());
        TABLE_MONEY+=b;
    }

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
