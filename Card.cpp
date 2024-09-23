#include "Card.h"
#include "Battle.h"
#include <iostream>
using namespace std;

Card::Card(const string& name, int cost): name(name), cost(cost) {}
Card::Card(): Card("Blank", 0) {}
Card::Card(const Card& card): name(card.name), cost(card.cost) {}

string Card::get_name() {
    return name;
}

void Card::set_name(const string& name) {
    this->name = name;
}

int Card::get_cost() {
    return cost;
}

void Card::set_cost(int cost) {
    this->cost = cost;
}


