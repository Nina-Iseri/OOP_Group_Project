#ifndef CARD_H
#define CARD_H

#include <string>

class Battle;

class Card {
protected:
    std::string name;
    int cost;

public:
    Card();
    Card(const std::string& name, int cost);
    Card(const Card&);

    std::string get_name();
    void set_name(const std::string&);
    int get_cost();
    void set_cost(int);
    virtual bool effect(Battle*) = 0;
    virtual void print_card_info() = 0;
};

#endif