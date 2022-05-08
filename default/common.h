#ifndef COMMON_H
#define COMMON_H
#include "sstream"
#include "functional"
typedef unsigned int usi;
struct Color{usi r,g,b;};
enum CARDNUM{
    two,//0 index
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,//13 index
};
enum CARDCOLOR{
    hearts,//kör
    tiles,//káró
    clover,//tref
    pikes//pikk
};
template<typename T> std::string convts(T a){//type T to string
    std::stringstream ss;
    ss<<a;
    std::string r;
    ss>>r;
    return r;
}
#endif // COMMON_H
