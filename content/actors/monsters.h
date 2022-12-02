#pragma once

#include "monstertype.h"
#include "wander.h"
#include "move.h"
#include "rest.h"

namespace Monsters {
    
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me); 
    MonsterType goblin();
    MonsterType skeleton();
    MonsterType zombie();

}
