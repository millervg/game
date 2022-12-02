#include <iostream>

#include "wander.h"
#include "actor.h"
#include "tile.h"
#include "engine.h"
#include "move.h"

Wander::Wander(Vec position)
    :position(position) {}

Result Wander::perform(Engine& engine) { 
    Vec pos = actor->get_position(); 
    std::vector<Vec> neighbors = engine.dungeon.neighbors(pos); 
    // randomize directions 
    shuffle(std::begin(neighbors), std::end(neighbors));  
    for (const Vec& neighbor : neighbors) { 
        Tile& tile = engine.dungeon.tiles(neighbor); 
        if (!tile.is_wall() && !tile.actor) { 
            Vec direction = neighbor - position; 
            return alternative(Move{direction}); 
        } 
    }
}