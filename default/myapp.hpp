#ifndef MYAPP_HPP
#define MYAPP_HPP
#include "application.hpp"
#include "card.hpp"
#include "iostream"
#include "widget.hpp"
#include "profile.hpp"
#include "button.hpp"
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
    void bet_by_player(Profile*,usi);
private:
    usi TABLE_MONEY;
    std::vector<Card*> deck;
    std::vector<Card*> table;
    std::vector<Widget*> widgets;
};

#endif // MYAPP_HPP
