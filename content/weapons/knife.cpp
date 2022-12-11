#include "knife.h"
#include "hit.h"
#include "engine.h"
#include "swing.h"

Knife::Knife(int damage)
    :Weapon{"knife", damage} {}

void Knife::use(Engine& engine, Actor& attacker, Actor& defender) {
    Vec direction = defender.get_position() - attacker.get_position();
    engine.events.add(Swing{sprite, direction, defender, damage});
}