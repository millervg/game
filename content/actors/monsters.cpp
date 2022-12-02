#include "monsters.h"
#include "monster.h"
#include "monstertype.h"
#include "randomness.h"
#include "engine.h"
#include "none.h"
namespace Monsters {
    std::unique_ptr<Action> default_behavior(Engine& engine, Monster& me) { 
        // pursue Hero if monster can see him (If Hero sees me, I see him) 
        if (me.is_visible() && engine.hero) { 
            Vec from = me.get_position(); 
            Vec to = engine.hero->get_position(); 
            std::vector<Vec> path = engine.dungeon.calculate_path(from, to); 
            if (path.size() > 1) { 
                Vec direction = path.at(1) - path.at(0); 
                return std::make_unique<Move>(direction); 
            } 
        } 
        // Monster doesn't see Hero 
        if (probability(66)) { 
            return std::make_unique<Wander>(); 
        } 
        else { 
            return std::make_unique<Rest>(); 
        } 
    }

    MonsterType goblin() { 
        int health = 2; 
        return {"goblin", default_speed, health, std::make_shared<None>(),
            default_behavior}; 
    } 

    MonsterType skeleton() {
        int health = 2;
        return {"skeleton", default_speed, health, std::make_shared<None>(),
            default_behavior};
    }

    MonsterType zombie() {
        int health = 2;
        return {"zombie", default_speed, health, std::make_shared<None>(),
            default_behavior};
    }
}