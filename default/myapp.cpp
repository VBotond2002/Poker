#include "myapp.hpp"
using namespace genv;
MyApp::MyApp(usi _W_, usi _H_):Application(_W_,_H_)
{
    testcard=new Card(10,10,57,89,ace,hearts);
    setbackgroundcolor(49, 112, 24);
    gout.load_font("LiberationSans-Regular.ttf",20);
}
MyApp::~MyApp(){

}
void MyApp::handle(event ev){
    testcard->handle(ev);
}
void MyApp::update(){
    testcard->update();
}
void MyApp::show(){
    Color *a=&background_color;
    gout<<color(a->r,a->g,a->b);
    gout<<move_to(0,0);
    gout<<box(_W,_H);
    testcard->show();
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
