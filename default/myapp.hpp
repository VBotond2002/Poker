#ifndef MYAPP_HPP
#define MYAPP_HPP
#include "application.hpp"
#include "card.hpp"
#include "iostream"
#include "widget.hpp"
#include "profile.hpp"
class MyApp: public Application
{
public:
    MyApp(usi _W_, usi _H_);
    virtual ~MyApp();
    void handle(genv::event ev);
    void show();
    void update();
    void apploop();
    void card_to_player();
private:
    std::vector<Card*> deck;
    std::vector<Widget*> widgets;
};

#endif // MYAPP_HPP
