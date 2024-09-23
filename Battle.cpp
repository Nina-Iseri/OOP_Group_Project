#include "Battle.h"
#include <random>
#include <algorithm>
#include <iostream>
using namespace std;

Battle::Battle(Player& mina, Enemy& oppo): mina(mina), oppo(oppo) {
    // turn = 0;
    card_queue = mina.get_card_deck();
    card_in_hand = {};
    discard_pile = {};
}

void Battle::run() {
    // run the battle
    cout << mina.get_name()+" vs "+oppo.get_name() << endl;
    cout << "Battle start!\n";
    do {
        mina.mana_recover();
        draw_cards(5);

        // player turn
        cout << "Your turn:\n";
        bool turn_over = false;
        while (true) {
            print_status();
            bool turn_over = mina.take_action(this);
            if (turn_over) break;
            if (oppo.get_current_life() < 0) {
                cout << oppo.get_name() << " has been defeated!\n";
                return;
            }
        }
        drop_cards();
        
        // enemy turn
        cout << "Enemy turn:\n";
        oppo.take_action(this);
    } while (mina.get_current_life() > 0);
    cout << "Wasted\n";
}

void Battle::draw_cards(int k) {
    // randomize card queue
    auto rng = default_random_engine {};
    shuffle(card_queue.begin(), card_queue.end(), rng);

    // draw k cards
    for (int i = 0; card_queue.size() && i < k; i++) {
        card_in_hand.push_back(card_queue[card_queue.size() - 1]);
        card_queue.pop_back();

        // recycle cards in discard pile if needed
        if (!card_queue.size() && discard_pile.size()) {
            recycle_cards();
        }
    }

}

void Battle::recycle_cards() {
    for (int i = 0; i < discard_pile.size(); i++) {
        card_queue.push_back(discard_pile[discard_pile.size() - 1]);
        discard_pile.pop_back();
    }
}

void Battle::drop_hand_card(int id) {
    discard_pile.push_back(card_in_hand[id]);
    card_in_hand.erase(next(card_in_hand.begin(), id));
}

void Battle::drop_cards() {
    int count = card_in_hand.size();
    for (int i = 0; i < count; i++) {
        discard_pile.push_back(card_in_hand[card_in_hand.size() - 1]);
        card_in_hand.pop_back();
    }
}

Player& Battle::get_mina() {
    return mina;
}

Enemy& Battle::get_oppo() {
    return oppo;
}


std::vector<Card*>& Battle::get_card_in_hand() {
    return card_in_hand;
}

void Battle::print_status() {
    cout << "mana left: " << mina.get_current_mana() << ", shield: " << mina.get_shield() << ", Mina life: " << mina.get_current_life() << ", "+oppo.get_name()+" life: " << oppo.get_current_life() << endl;
}