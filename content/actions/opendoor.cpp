#include "opendoor.h"
#include "actor.h"
#include "engine.h"
#include "dungeon.h"
#include "updatefov.h"
#include <iostream>


OpenDoor::OpenDoor(Vec position) : position{position} {}

Result OpenDoor::perform(Engine& engine) {
    Tile& tile = engine.dungeon.tiles(position);
    if (tile.is_door()) {
         Door& door = engine.dungeon.doors.at(position);
         door.open();
         tile.walkable = true;
         engine.events.add(UpdateFOV{});
         return success();
    }
    else {
        return failure();
    }
   
    
}