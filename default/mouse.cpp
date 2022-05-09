#include "mouse.hpp"
using namespace genv;
Mouse::Mouse()
{

}
Mouse::~Mouse(){}
void Mouse::handle(event ev){

}
void Mouse::update(event ev){

}
void Mouse::show(){

}
void Mouse::set_if_action(std::function<bool()> f){
    if_action=f;
}
void Mouse::set_if_action_2(std::function<bool()> f){
    if_action_2=f;
}
void Mouse::track_if_action_m(event ev){
    if(if_action()&&ev.type==ev_mouse){
        mx=ev.pos_x;
        my=ev.pos_y;
    }
}
void Mouse::track_if_action_m2(event ev){
    if(if_action_2()&&ev.type==ev_mouse){
        m2x=ev.pos_x;
        m2y=ev.pos_y;
    }
}
int Mouse::x_diff(){
    return m2x-mx;
}
int Mouse::y_diff(){
    return m2y-my;
}
bool Mouse::mouse_moved(){
    return m2x!=mx||m2y!=my;
}
