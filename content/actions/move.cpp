#include <iostream>

#include "move.h"
#include "actor.h"
#include "tile.h"
#include "engine.h"
#include "opendoor.h"
#include "closedoor.h"
#include "attack.h"
#include "dungeon.h"
#include "door.h"

Move::Move(Vec direction)
    :direction(direction) {}

Result Move::perform(Engine& engine) {
    Vec position = actor->get_position();
    Vec new_position = position + direction;
    actor->change_direction(direction);
    
    Tile& tile = engine.dungeon.tiles(new_position);
    if (tile.is_wall()) {
        return failure();
    }

    if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(new_position);
        if (!door.is_open()) {
            return alternative(OpenDoor{new_position});
        }
    }

    if(tile.actor) {
        return alternative(Attack{*tile.actor});
    }

    actor->move_to(new_position);
    return success();
}   

