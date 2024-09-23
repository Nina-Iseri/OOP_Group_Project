#include <iostream>
#include <string>
#include <vector>
#include "Will.h"
#include "Player.h"
#include "Enemy.h"
#include "Card.h"
#include "BasicCard.h"
#include "Battle.h"
using namespace std;

int main(void) {
    BasicCard attack("Attack", 1, 6, 0), defence("Defence", 1, 0, 5);
    vector<BasicCard> cards(6, attack);
    for (int i = 0; i < 6; i++) {
        cards.push_back(defence);
    }
    vector<Card*> card_deck;
    for (int i = 0; i < 12; i++) {
        card_deck.push_back(&cards[i]);
    }
    Player mina("Mina", 60, card_deck);
    Enemy lancer;
    Battle fight_0(mina, lancer);
    fight_0.run();

    return 0;
}