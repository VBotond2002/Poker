#include "application.hpp"
const unsigned int _W=600,_H=400;
int main()
{
    Application app(_W,_H);
    app.setbackgroundcolor(49, 112, 24);
    app.apploop();
    return 0;
}
