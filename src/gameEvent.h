#pragma once
#include "ofMain.h"
#include "character.h"
#include "Bullet.h"

#define GAME_LOST 3

class GameEvent : public ofEventArgs {

public:
    Bullet* bullet;
    Destructible* chara_;
    int score_;
    string   message;

    GameEvent() {
        bullet = NULL;
        chara_ = NULL;
    }

    static ofEvent <GameEvent> events_;
};

class GameStateEvent : public ofEventArgs {
    
public:
    string message;
    int state_;

    static ofEvent <GameStateEvent> events_;
};

