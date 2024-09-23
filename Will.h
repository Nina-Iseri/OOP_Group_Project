#ifndef WILL_H
#define WILL_H

#include <string>

class Battle;

class Will {  // common attibutes of characters including player and enemy
protected:
    std::string name;
    int total_life;
    int current_life;
    int shield;  // default = 0

public:
    Will();
    Will(const std::string& name, int life);
    Will(Will& someone);

    int get_total_life();
    void set_toal_life(int);

    int get_current_life();
    void set_current_life(int);

    std::string get_name();
    void set_name(const std::string&);

    virtual bool take_action(Battle*) = 0;
    void take_damage(int);
    int get_shield();
    void shield_cover(int);
};

#endif