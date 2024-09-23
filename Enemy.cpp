#include "Enemy.h"
#include "Battle.h"
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

Enemy::Enemy(): Will("Lancer", 30) {}

bool Enemy::take_action(Battle* battle) {
    cout << "Lancer is rushing over!\n";
    this_thread::sleep_for(chrono::seconds(1)); // pause 1 second
    battle->get_mina().take_damage(9);
    return 0;
}