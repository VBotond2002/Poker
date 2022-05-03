#ifndef APPLICATION_HPP
#define APPLICATION_HPP
#include "graphics.hpp"
#include "vector"
#include "common.h"
typedef unsigned int usi;

class Application
{
public:
    Application(usi, usi);
    void setbackgroundcolor(usi,usi,usi);
    void setbackgroundcolor(Color c);
    virtual void handle(genv::event ev)=0;
    virtual void show()=0;
    virtual  void update()=0;
    virtual void apploop()=0;
    virtual ~Application();
protected:
    //std::vector<Widget*> container
    Color background_color;
    usi _W,_H;
};

#endif // APPLICATION_HPP
