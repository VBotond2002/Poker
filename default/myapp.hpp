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
#include "slider.hpp"
enum PHASE{
    BEFORE_FLOP,
    FLOP,
    TURN,
    RIVER,
    PAY
};
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
    void bet_by_player();
    Card* pick_random_card();
    void release_hand();
    void release_flop();
    void release_turn();
    void release_river();
    void clear_hand();
    void clear_table();
    bool is_released_hand();
    void next_phase();
    bool search_pair();
    bool search_drill();
    bool search_poker();
    bool search_flush();
    bool search_row();
    void pay();
private:
    bool action_performed=true;
    usi TABLE_MONEY;
    Profile* p1;
    Profile* p2;
    Slider* sl1;
    std::vector<Card*> deck;
    std::vector<Card*> table;
    std::vector<Widget*> widgets;
   PHASE current_phase=BEFORE_FLOP;
};

#endif // MYAPP_HPP
