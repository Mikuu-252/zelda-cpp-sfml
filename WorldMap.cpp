

#include "WorldMap.h"

WorldMap::WorldMap() {
    init();
}


void WorldMap::init() {
    activeLevel.x=1;
    activeLevel.y=3;
    activeLevel.z=0;


    prepareLevel0();
    prepareLevel130();
    prepareLevel030();
}

void WorldMap::prepareLevel0() {
    Level level;


    levels.push_back(level);
}

void WorldMap::prepareLevel130() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=3;
    level.levelCoordinate.z=0;

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

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=3;
    level.levelCoordinate.z=0;

    level.walls.push_back(Wall(0,8,32,"wall12x2"));
    level.walls.push_back(Wall(11,2,32,"wall1x3"));
    level.walls.push_back(Wall(0,2,32,"wall2x6"));

    //shop
    level.walls.push_back(Wall(2,2,32,"shop2x3-left"));
    level.walls.push_back(Wall(6,2,32,"shop2x3-right"));


    levels.push_back(level);
}

void WorldMap::debugLevel() {
    activeLevel.x=0;
    activeLevel.y=3;
    activeLevel.z=0;
}

const Level &WorldMap::getLevel() const {
    int index = 0;
    for (Level level: levels) {
        if(level.levelCoordinate.x == activeLevel.x && level.levelCoordinate.y == activeLevel.y && level.levelCoordinate.z == activeLevel.z) {
            return levels[index];
        }
        index++;
    }
    return levels[0];
}




