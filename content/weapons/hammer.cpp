#include "hammer.h"
#include "hit.h"
#include "engine.h"
#include "spin.h"
#include "animation.h"

Hammer::Hammer(int damage)
    :Weapon{"hammer", damage} {}

void Hammer::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Spin{sprite, direction, defender, damage});
    //engine.events.add(FireEvent{defender.get_position()});
}
