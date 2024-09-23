#ifndef BASICCARD_H
#define BASICCARD_H

#include "Card.h"

class Battle;

class BasicCard: public Card {
private:
    int damage;
    int shield;
public:
    BasicCard(const std::string& name, int cost, int damage = 0, int shield = 0);
    BasicCard(const BasicCard&);
    bool effect(Battle*);
    void print_card_info();
};

#endif