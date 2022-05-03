#include "profile.hpp"
using namespace genv;
Profile::Profile(usi a,usi b,usi c,usi d): Widget(a,b,c,d)
{

}
void Profile::setbase_color(usi a, usi b, usi c){
    base_color={a,b,c};
}
void Profile::sethh_color(usi a, usi b, usi c){
    hh_color={a,b,c};
}
void Profile::handle(genv::event){

}
void Profile::update(){

}
void Profile::show(){
    if(selected)gout<<color(hh_color.r,hh_color.g,hh_color.b);
    else gout<<color(base_color.r,base_color.g,base_color.b);
}
Profile::~Profile(){}
