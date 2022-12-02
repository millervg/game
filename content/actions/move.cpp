#include <iostream>

#include "move.h"
#include "actor.h"
#include "tile.h"
#include "engine.h"
#include "opendoor.h"
#include "closedoor.h"

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

      if (tile.is_door()) {
        Door& door = engine.dungeon.doors.at(position);
        if (!door.is_open()) {
            return alternative(OpenDoor{new_position});
        }
    }

        actor->move_to(new_position);
        return success();

}   

