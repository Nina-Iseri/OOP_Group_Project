#ifndef BATTLE_H
#define BATTLE_H

#include "Will.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include <string>
#include <vector>

class Battle {
private:
    // int turn;
    Player& mina;
    Enemy& oppo;
    std::vector<Card*> card_queue;
    std::vector<Card*> card_in_hand;
    std::vector<Card*> discard_pile;
    
public:
    Battle(Player&, Enemy&);
    void run();
    void draw_cards(int);  // randomly draw 5 cards from card queue
    void recycle_cards();
    std::vector<Card*>& get_card_in_hand();
    void drop_hand_card(int id);
    void drop_cards();
    Player& get_mina();
    Enemy& get_oppo();
    void print_status();
};

#endif