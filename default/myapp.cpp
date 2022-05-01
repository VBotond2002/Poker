#include "myapp.hpp"
using namespace genv;
MyApp::MyApp(usi _W_, usi _H_):Application(_W_,_H_)
{
    testcard=new Card(0,0,20,40,two,pikes);
    setbackgroundcolor(49, 112, 24);
}
MyApp::~MyApp(){

}
void MyApp::handle(event ev){

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
        update();
        show();
    }
}
