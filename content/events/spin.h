#pragma once

#include "actor.h"
#include "event.h"

class Spin: public Event {
public:
    Spin(Sprite& sprite, Vec direction, Actor& defender, int damage);
    //                                          ^ needed for hit ^
    void execute(Engine& engine) override;
    void when_done(Engine& engine) override;
private:
    Sprite& sprite;
    Sprite copy;
    Actor& defender;
    int damage;
    double starting_angle, delta;
};