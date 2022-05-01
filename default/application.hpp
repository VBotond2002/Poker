#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "graphics.hpp"
#include "vector"
typedef unsigned int usi;
struct Color{usi r,g,b;};
class Application
{
public:
    Application(usi, usi);
    void setbackgroundcolor(usi,usi,usi);
    void setbackgroundcolor(Color c);
    void show();
    void update();
    void apploop();
    virtual ~Application();
protected:
    //std::vector<Widget*> container
    Color background_color;
    usi _W,_H;
};

#endif // APPLICATION_HPP
