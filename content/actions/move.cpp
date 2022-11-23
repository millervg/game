#include "move.h"
#include "actor.h"
#include "tile.h"
#include "engine.h"
#include <iostream>

Move::Move(Vec direction)
    :direction(direction) {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    actor->change_direction(direction);
    
    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall() || tile.actor) {
        return failure();
    }
    else if (tile.is_door()) {
        return failure();
    }
    else {
        actor->move_to(new_position);
        return success();
    }
}   

