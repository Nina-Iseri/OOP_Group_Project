#include "BasicCard.h"
#include "Battle.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

BasicCard::BasicCard(const std::string& name, int cost, int damage, int shield): Card(name, cost) {
    this->damage = damage;
    this->shield = shield;
}

BasicCard::BasicCard(const BasicCard& card): Card(card) {
    damage = card.damage;
    shield = card.shield;
}

bool BasicCard::effect(Battle* battle) {
    if (!battle->get_mina().consume_mana(cost)) return false;
    if (damage) {
        battle->get_oppo().take_damage(damage);
        cout << "Fire!\n";
        this_thread::sleep_for(chrono::seconds(1)); // pause 1 second
    }
    if (shield) {
        battle->get_mina().shield_cover(shield);
        cout << "Hide!\n";
        this_thread::sleep_for(chrono::seconds(1)); // pause 1 second
    }
    return true;
}

void BasicCard::print_card_info() {
    cout << "(Cost: " << cost << ") " << name << ": ";
    if (damage) cout << "deal " << damage << " damage to enemy, ";
    if (shield) cout << "gain " << shield << " shield, ";
    cout << endl;
}