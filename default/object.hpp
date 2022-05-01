#ifndef OBJECT_HPP
#define OBJECT_HPP
#include "graphics.hpp"
struct Color{unsigned int r,g,b;};
class Object
{
public:
    Object(unsigned int, unsigned int, unsigned int, unsigned int);
    virtual ~Object();
    virtual void handle(genv::event)=0;
    virtual void update()=0;
    virtual void show()=0;
protected:
    unsigned int x,y,w,h;
};

#endif // OBJECT_HPP
