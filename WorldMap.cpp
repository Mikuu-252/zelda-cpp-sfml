

#include "WorldMap.h"

WorldMap::WorldMap() {
    init();
}


void WorldMap::init() {
    prepareLevel130();
    prepareLevel030();
}

void WorldMap::prepareLevel130() {
    Level level;

    //Floor
    for (int x = 5; x < 10; ++x) {
        for (int y = 2; y < 5; ++y) {
            level.floors.push_back(Floor(x,y,32,"grass"));
        }
    }

    for (int x = 0; x < 10; ++x) {
        for (int y = 5; y < 8; ++y) {
            level.floors.push_back(Floor(x,y,32,"grass"));
        }
    }

    //Walls
    level.walls.push_back(Wall(0,8,32,"wall12x2"));
    level.walls.push_back(Wall(10,2,32,"wall2x6"));
    level.walls.push_back(Wall(0,2,32,"wall5x3"));
    //level.walls.push_back(Wall(5,2,32,"wall1x3"));  //Door


    levels.push_back(level);

}

void WorldMap::prepareLevel030() {
    Level level;

    level.walls.push_back(Wall(0,8,32,"wall12x2"));
    level.walls.push_back(Wall(11,2,32,"wall1x3"));
    level.walls.push_back(Wall(0,2,32,"wall2x6"));

    //shop
    level.walls.push_back(Wall(2,2,32,"shop2x3-left"));
    level.walls.push_back(Wall(6,2,32,"shop2x3-right"));


    levels.push_back(level);
}

void WorldMap::debugLevelInc() {
    activeLevel += 1;
}

const Level &WorldMap::getLevel() const {
    return levels[activeLevel];
}




