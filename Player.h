#ifndef PLAYER_H
#define PLAYER_H

#include "Will.h"
#include "Card.h"
#include <vector>

class Battle;

class Player: public Will {
private:
    std::vector<Card*> card_deck;  // cards obtained
    int mana;  // mana limit in each turn
    int current_mana;

public:
    Player(const std::string& name, int life, std::vector<Card*> card_deck);

    std::vector<Card*> get_card_deck();
    int get_mana();
    void set_mana(int);

    int get_current_mana();
    bool consume_mana(int);
    void mana_recover();
    void shield_cover(int);

    bool take_action(Battle* battle); // return true to finish current turn
};



#endif