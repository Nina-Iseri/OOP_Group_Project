#include "Player.h"
#include "Battle.h"
#include <chrono>
#include <thread>
#include <iostream>
using namespace std;

Player::Player(const string& name, int life, vector<Card*> card_deck): Will(name, life), card_deck(card_deck) {
    mana = 3;
    current_mana = 3;
}

bool Player::take_action(Battle* battle) {
    // select a card to use
    cout << "Enter a lowercase character to select the card to use\n";
    for (int i = 0; i < battle->get_card_in_hand().size(); i++) {
        cout << (char)('a' + i) << "  - ";
        battle->get_card_in_hand()[i]->print_card_info();
    }

    // use a card or finish the turn
    cout << "Enter a lowercase: (0 to finish current turn)\n";
    char id;
    cin >> id;
    if (id == '0') return true;  // finish the turn
    while ((id < 'a') || (id >= 'a' + battle->get_card_in_hand().size())) {
        if (id == '0') return true;  // finish the turn
        cout << "Please enter a valid character\n";
        cin >> id;
    }
    if (battle->get_card_in_hand()[id - 'a']->effect(battle)) {
        battle->drop_hand_card(id - 'a');
    } else {
        cout << "Mana not enough\n";
        this_thread::sleep_for(chrono::seconds(1)); // pause 1 second
    }

    return false;
}

vector<Card*> Player::get_card_deck(){
    return card_deck;
}

int Player::get_mana() {
    return mana;
}

void Player::set_mana(int mana) {
    this->mana = mana;
}

int Player::get_current_mana() {
    return current_mana;
}

bool Player::consume_mana(int cost) {
    if (cost > current_mana) return false;
    current_mana -= cost;
    return true;
}

void Player::mana_recover() {
    current_mana = mana;
}

void Player::shield_cover(int shield) {
    this->shield += shield;
}
