#ifndef MYAPP_HPP
#define MYAPP_HPP
#include "application.hpp"
#include "card.hpp"
#include "iostream"
class MyApp: public Application
{
public:
    MyApp(usi _W_, usi _H_);
    virtual ~MyApp();
    void handle(genv::event ev);
    void show();
    void update();
    void apploop();
private:
    std::vector<Card*> deck;
};

#endif // MYAPP_HPP
