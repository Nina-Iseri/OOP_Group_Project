#ifndef ENEMY_H
#define ENEMY_H

#include "Will.h"

class Battle;

class Enemy: public Will {
private:

public:
    Enemy();
    bool take_action(Battle*);
};

#endif