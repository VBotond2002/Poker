#include "graphics.hpp"
using namespace genv;

const unsigned int _W=600,_H=400;
int main()
{
    gout.open(_W,_H);
    gout<<refresh;
    event ev;
    while(gin >> ev) {
    }
    return 0;
}
