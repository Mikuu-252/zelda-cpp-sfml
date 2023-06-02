

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

    prepareLevel120();
    prepareLevel020();

    prepareLevel110();
    prepareLevel010();

    prepareLevel100();
    prepareLevel000();
}

void WorldMap::prepareLevel0() {
    Level level;

    level.levelCoordinate.x=-1;
    level.levelCoordinate.y=-1;
    level.levelCoordinate.z=-1;

    levels.push_back(level);
}

void WorldMap::prepareLevel130() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=3;
    level.levelCoordinate.z=0;

    //Floor
/*    for (int x = 5; x < 10; ++x) {
        for (int y = 2; y < 5; ++y) {
            level.floors.push_back(Floor(x,y,32,"grass"));
        }
    }

    for (int x = 0; x < 10; ++x) {
        for (int y = 5; y < 8; ++y) {
            level.floors.push_back(Floor(x,y,32,"grass"));
        }
    }*/

    //Walls
    level.walls.push_back(Wall(0,8,32,"wall12x2"));
    level.walls.push_back(Wall(10,2,32,"wall2x6"));
    level.walls.push_back(Wall(0,2,32,"wall4x3"));
    //level.walls.push_back(Wall(4,2,32,"wall1x3"));  //Door
    level.walls.push_back(Wall(5,2,32,"wall1x3"));

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
    level.walls.push_back(Wall(4,2,32,"shop2x3-center")); //doors
    level.walls.push_back(Wall(6,2,32,"shop2x3-right"));


    levels.push_back(level);
}

void WorldMap::debugLevel() {
    activeLevel.x=-1;
    activeLevel.y=-1;
    activeLevel.z=-1;
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

void WorldMap::changeActiveLevel(int x, int y, int z) {
    activeLevel.x += x;
    activeLevel.y += y;
    activeLevel.z += z;
}

void WorldMap::prepareLevel120() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=2;
    level.levelCoordinate.z=0;

    //Floor

    //Walls
    level.walls.push_back(Wall(0,2,32,"wall2x2"));
    level.walls.push_back(Wall(10,2,32,"wall2x8"));
    level.walls.push_back(Wall(0,7,32,"wall6x3"));

    levels.push_back(level);
}

void WorldMap::prepareLevel020() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=2;
    level.levelCoordinate.z=0;

    //Floor

    //Walls
    level.walls.push_back(Wall(10,2,32,"wall2x2"));
    level.walls.push_back(Wall(0,2,32,"wall2x8"));
    level.walls.push_back(Wall(0,7,32,"wall6x3"));
    level.walls.push_back(Wall(11,7,32,"wall1x3"));


    levels.push_back(level);
}

void WorldMap::prepareLevel110() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=1;
    level.levelCoordinate.z=0;

    //Floor

    //Walls
    level.walls.push_back(Wall(0,2,32,"wall3x3"));
    //level.walls.push_back(Wall(4,2,32,"wall1x3")); //door
    level.walls.push_back(Wall(5,2,32,"wall1x3"));

    level.walls.push_back(Wall(10,2,32,"wall2x8"));
    level.walls.push_back(Wall(0,8,32,"wall2x2"));


    levels.push_back(level);
}

void WorldMap::prepareLevel010() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=1;
    level.levelCoordinate.z=0;

    //Floor

    //Walls
    level.walls.push_back(Wall(0,2,32,"wall2x8"));
    level.walls.push_back(Wall(2,2,32,"wall3x3"));
    //level.walls.push_back(Wall(5,2,32,"wall1x3")); //door
    level.walls.push_back(Wall(6,2,32,"wall1x3"));

    level.walls.push_back(Wall(10,2,32,"wall2x3"));
    level.walls.push_back(Wall(10,8,32,"wall2x2"));


    levels.push_back(level);
}

void WorldMap::prepareLevel100() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=0;
    level.levelCoordinate.z=0;

    //Floor

    //Walls
    level.walls.push_back(Wall(0,2,32,"wall12x2"));
    level.walls.push_back(Wall(10,4,32,"wall2x6"));
    level.walls.push_back(Wall(0,9,32,"wall5x1"));


    levels.push_back(level);
}

void WorldMap::prepareLevel000() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=0;
    level.levelCoordinate.z=0;

    //Floor

    //Walls
    level.walls.push_back(Wall(0,2,32,"wall12x2"));
    level.walls.push_back(Wall(0,4,32,"wall2x6"));
    level.walls.push_back(Wall(2,9,32,"wall5x1"));
    level.walls.push_back(Wall(10,9,32,"wall2x1"));

    //Dung
    level.walls.push_back(Wall(3,4,32,"dung2x3-left"));
    level.walls.push_back(Wall(5,4,32,"dung2x3-center")); //doors
    level.walls.push_back(Wall(7,4,32,"dung2x3-right"));


    levels.push_back(level);
}




