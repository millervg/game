#include "engine.h"
#include "heros.h"
#include "monsters.h"

int main() {
    std::string filename{"settings.txt"};
    Settings settings = read_settings(filename);
    Engine engine{settings};

    engine.create_hero(Heros::knight);
    MonsterType new_monster_type = Monsters::goblin();
    engine.create_monster(new_monster_type);
    MonsterType new_monster_type2 = Monsters::skeleton();
    engine.create_monster(new_monster_type2);
    MonsterType new_monster_type3 = Monsters::zombie();
    engine.create_monster(new_monster_type3);
    engine.run();
}
