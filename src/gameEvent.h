#pragma once
#include "ofMain.h"
#include "character.h"
#include "Bullet.h"

class GameEvent : public ofEventArgs {

public:

    Bullet* bullet;
    Destructible* chara_;
    string   message;

    GameEvent() {
        bullet = NULL;
        chara_ = NULL;
    }

    static ofEvent <GameEvent> events_;
};

