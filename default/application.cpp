#include "application.hpp"
using namespace genv;
Application::Application(usi _W_, usi _H_): _W(_W_),_H(_H_)
{
    gout.open(_W,_H);
    gout<<refresh;
}
void Application::setbackgroundcolor(usi r, usi g, usi b){
    background_color.r=r;
    background_color.g=g;
    background_color.b=b;
}
void Application::setbackgroundcolor(Color c){
    background_color=c;
}
void Application::show(){
    Color *a=&background_color;
    gout<<color(a->r,a->g,a->b);
    gout<<move_to(0,0);
    gout<<box(_W,_H);
    gout<<refresh;
}
void Application::update(){

}
void Application::apploop(){
    event ev;
    while(gin>>ev){
        update();
        show();
    }
}
Application::~Application(){
    //TODO loop through the vector and delete the heap allocations
}
