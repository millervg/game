#include "attack.h"
#include "engine.h"

Attack::Attack(Actor& defender) 
    : defender{defender} {}

Result Attack::perform(Engine&) {
    actor->attack(defender);
    return success();
}