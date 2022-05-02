#include "card.hpp"
using namespace genv;
void Card::loadimage(std::string path){
    std::ifstream in;
    int img_w,img_h;
    in.open(path);
    in>>img_w;
    in>>img_h;
    for(int i=0;i<img_h;i++){
       for(int j=0;j<img_w;j++){
           std::vector<int> add;
           for(int k=0;k<3;k++){
               int tempval;
               in>>tempval>>std::ws;
               add.push_back(tempval);
           }
           //std::cout<<add[0]<<","<<add[1]<<","<<add[2]<<std::endl;
           img.push_back(add);
       }
    }

     in.close();
}
Card::Card(usi a, usi b, usi c, usi d,CARDNUM e,CARDCOLOR col): Object(a,b,c,d)
{
    type=e;
    ccolor=col;
    x=a;
    y=b;
    w=c;
    h=d;

    if(ccolor==hearts){
        switch(type){
        case two:
            loadimage("src/H2.bmp.kep");
            break;
        case three:
            loadimage("src/H3.bmp.kep");
             break;
        case four:
            loadimage("src/H4.bmp.kep");
             break;
        case five:
            loadimage("src/H5.bmp.kep");
             break;
        case six:
            loadimage("src/H6.bmp.kep");
             break;
        case seven:
            loadimage("src/H7.bmp.kep");
             break;
        case eight:
            loadimage("src/H8.bmp.kep");
             break;
        case nine:
            loadimage("src/H9.bmp.kep");
             break;
        case ten:
            loadimage("src/H10.bmp.kep");
             break;
        case jack:
            loadimage("src/Hj.bmp.kep");
             break;
        case queen:
            loadimage("src/Hq.bmp.kep");
             break;
        case king:
            loadimage("src/Hk.bmp.kep");
             break;
        case ace:
            loadimage("src/Ha.bmp.kep");
             break;
        }
    }if(ccolor==tiles){
        switch(type){
            case two:
            loadimage("src/D2.bmp.kep");
            break;
        case three:
            loadimage("src/D3.bmp.kep");
             break;
        case four:
            loadimage("src/D4.bmp.kep");
             break;
        case five:
            loadimage("src/D5.bmp.kep");
             break;
        case six:
            loadimage("src/D6.bmp.kep");
             break;
        case seven:
            loadimage("src/D7.bmp.kep");
             break;
        case eight:
            loadimage("src/D8.bmp.kep");
             break;
        case nine:
            loadimage("src/D9.bmp.kep");
             break;
        case ten:
            loadimage("src/D10.bmp.kep");
             break;
        case jack:
            loadimage("src/Dj.bmp.kep");
             break;
        case queen:
            loadimage("src/Dq.bmp.kep");
             break;
        case king:
            loadimage("src/Dk.bmp.kep");
             break;
        case ace:
            loadimage("src/Da.bmp.kep");
             break;
        }
    }if(ccolor==clover){
        switch(type){
            case two:
            loadimage("src/C2.bmp.kep");
            break;
        case three:
            loadimage("src/C3.bmp.kep");
             break;
        case four:
            loadimage("src/C4.bmp.kep");
             break;
        case five:
            loadimage("src/C5.bmp.kep");
             break;
        case six:
            loadimage("src/C6.bmp.kep");
             break;
        case seven:
            loadimage("src/C7.bmp.kep");
             break;
        case eight:
            loadimage("src/C8.bmp.kep");
             break;
        case nine:
            loadimage("src/C9.bmp.kep");
             break;
        case ten:
            loadimage("src/C10.bmp.kep");
             break;
        case jack:
            loadimage("src/Cj.bmp.kep");
             break;
        case queen:
            loadimage("src/Cq.bmp.kep");
             break;
        case king:
            loadimage("src/Ck.bmp.kep");
             break;
        case ace:
            loadimage("src/Ca.bmp.kep");
             break;
        }
    }if(ccolor==pikes){
        switch(type){
            case two:
            loadimage("src/S2.bmp.kep");
            break;
        case three:
            loadimage("src/S3.bmp.kep");
             break;
        case four:
            loadimage("src/S4.bmp.kep");
             break;
        case five:
            loadimage("src/S5.bmp.kep");
             break;
        case six:
            loadimage("src/S6.bmp.kep");
             break;
        case seven:
            loadimage("src/S7.bmp.kep");
             break;
        case eight:
            loadimage("src/S8.bmp.kep");
             break;
        case nine:
            loadimage("src/S9.bmp.kep");
             break;
        case ten:
            loadimage("src/S10.bmp.kep");
             break;
        case jack:
            loadimage("src/Sj.bmp.kep");
             break;
        case queen:
            loadimage("src/Sq.bmp.kep");
             break;
        case king:
            loadimage("src/Sk.bmp.kep");
             break;
        case ace:
            loadimage("src/Sa.bmp.kep");
             break;
        }
    }
}
void Card::handle(event ev){

}
void Card::update(){

}
void Card::show(){
    int imgindex=0;
    for(size_t i=y;i<y+h;i++){
        for(size_t j=x;j<x+w;j++){
            gout<<move_to(j,i);
            gout<<color(img[imgindex][0],img[imgindex][1],img[imgindex][2]);
            gout<<dot;
            imgindex++;
        }
    }



}
Card::~Card(){

}
