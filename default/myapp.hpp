#ifndef MYAPP_HPP
#define MYAPP_HPP
#include "application.hpp"
#include "card.hpp"
#include "iostream"
#include "widget.hpp"
#include "profile.hpp"
#include "button.hpp"
#include "random"
#include "time.h"
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
    Card* pick_random_card();
    void release_hand();
    void release_flop();
    void release_turn();
    void release_river();
    void clear_hand();
    void clear_table();
    bool is_released_hand();
private:
    usi TABLE_MONEY;
    Profile* p1;
    Profile* p2;
    std::vector<Card*> deck;
    std::vector<Card*> table;
    std::vector<Widget*> widgets;
};

#endif // MYAPP_HPP
