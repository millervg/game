#include "hit.h"
#include "actor.h"
#include "engine.h"
#include "die.h"

Hit::Hit(Actor& actor, int damage)
    :actor{actor}, damage{damage} {}

void Hit::execute(Engine& engine) {
    actor.take_damage(damage);

    // remove the actor if dead
    if (actor.health <= 0) {
        // add event
        engine.events.add(Die{actor});
    }
}