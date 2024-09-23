#include "Will.h"
#include "Battle.h"
using namespace std;

Will::Will(const string& name, int life): name(name), total_life(life) {
    current_life = total_life;
    shield = 0;
}
Will::Will(): Will("init", 1) {}

Will::Will(Will& someone): name(someone.name), total_life(someone.total_life) {
    current_life = someone.current_life;
}

int Will::get_current_life() {
    return current_life;
}

void Will::set_current_life(int life) {
    current_life = life;
}

int Will::get_total_life() {
    return total_life;
}

void Will::set_toal_life(int life) {
    total_life = life;
    if (current_life > total_life) current_life = total_life;
}

string Will::get_name() {
    return name;
}

void Will::set_name(const string& name) {
    this->name = name;
}

void Will::take_damage(int damage) {
    shield -= damage;
    if (shield < 0) {
        current_life += shield;
        shield = 0;
    }
}

int Will::get_shield() {
    return shield;
}