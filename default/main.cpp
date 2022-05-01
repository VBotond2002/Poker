#include "myapp.hpp"
const unsigned int _W=600,_H=400;
int main()
{
    MyApp app(_W,_H);
    app.apploop();
    return 0;
}
