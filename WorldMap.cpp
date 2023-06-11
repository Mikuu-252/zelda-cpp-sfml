

#include "WorldMap.h"
#include "Items/Ruppes.h"
#include "Items/HealHeart.h"
#include "Items/MaxHeart.h"

WorldMap::WorldMap() {
    init();
}


void WorldMap::init() {
    activeLevel.x=1;
    activeLevel.y=3;
    activeLevel.z=0;


    prepareLevelDebug();

    prepareLevel130();
    prepareLevel030();
    prepareLevel03m1();

    prepareLevel120();
    prepareLevel020();

    prepareLevel110();
    prepareLevel010();

    prepareLevel100();
    prepareLevel000();
    prepareLevel00m1();
}


void WorldMap::debugLevel() {
    activeLevel.x=-1;
    activeLevel.y=-1;
    activeLevel.z=-1;
}

void WorldMap::resetLevel() {
    activeLevel.x=1;
    activeLevel.y=3;
    activeLevel.z=0;
}

Level &WorldMap::getLevel() {
    for (size_t idx=0; idx<levels.size(); idx++)
    {
        if(levels[idx].levelCoordinate.x == activeLevel.x
        && levels[idx].levelCoordinate.y == activeLevel.y
        && levels[idx].levelCoordinate.z == activeLevel.z)
        {
            return levels[idx];
        }
    }
    return levels[0];
}

void WorldMap::changeActiveLevel(int x, int y, int z) {
    activeLevel.x += x;
    activeLevel.y += y;
    activeLevel.z += z;
}


//Level prepare
void WorldMap::prepareLevelDebug() {
    Level level;

    level.levelCoordinate.x=-1;
    level.levelCoordinate.y=-1;
    level.levelCoordinate.z=-1;

    //level.pickUps.push_back(std::make_shared<Ruppes>("g-rupees", true, false, false,"Rupees", 1, 100, 100));
    //level.pickUps.push_back(std::make_shared<Ruppes>("b-rupees", true, false, false, "Rupees", 3, 150, 100));
    //level.pickUps.push_back(std::make_shared<Ruppes>("r-rupees", true, false, false, "Rupees", 5, 200, 100));

    //level.enemies.push_back(std::make_shared<Enemy>("shyguy", 150, 150, 0, 3, 1));

    //level.pickUps.push_back(std::make_shared<HealHeart>("heal", true, false, false, "Heal", 2, 100, 150));
    //level.pickUps.push_back(std::make_shared<HealHeart>("halfheal", true, false, false, "Heal", 1, 200, 150));

    //level.pickUps.push_back(std::make_shared<MaxHeart>("heartup", false, false, true, "MaxHeart", 6, 100, 200));


    levels.push_back(level);
}

void WorldMap::prepareLevel130() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=3;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,8,32,"wall12x2"));
    level.walls.push_back(std::make_shared<Wall>(10,2,32,"wall2x6"));
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall4x3"));
    //level.teleport = Teleport(4,2,32,"wall1x3");
    level.walls.push_back(std::make_shared<Wall>(4,2,32,"wall1x3"));
    level.walls.push_back(std::make_shared<Wall>(5,2,32,"wall1x3"));


    levels.push_back(level);
}

void WorldMap::prepareLevel030() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=3;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,8,32,"wall12x2"));
    level.walls.push_back(std::make_shared<Wall>(11,2,32,"wall1x3"));
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall2x6"));

    //Shop
    level.walls.push_back(std::make_shared<Wall>(2,2,32,"shop2x3-left"));
    level.walls.push_back(std::make_shared<Wall>(4,2,32,"shop2x3-center"));

    level.teleport = Teleport(4,4,32,"teleport1x2", 'D', 180,242);
    level.walls.push_back(std::make_shared<Wall>(6,2,32,"shop2x3-right"));


    levels.push_back(level);
}

void WorldMap::prepareLevel03m1() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=3;
    level.levelCoordinate.z=-1;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"shop-wall-top"));
    level.walls.push_back(std::make_shared<Wall>(0,4,32,"shop-wall"));
    level.walls.push_back(std::make_shared<Wall>(10,4,32,"shop-wall"));
    level.walls.push_back(std::make_shared<Wall>(2,8,32,"shop-wall-bottom"));
    level.walls.push_back(std::make_shared<Wall>(4,9,32,"shop-tp"));
    level.teleport = Teleport(4,9,32,"teleport1x4", 'U', 142,164);
    level.walls.push_back(std::make_shared<Wall>(8,8,32,"shop-wall-bottom"));

    //Items
    level.pickUps.push_back(std::make_shared<MaxHeart>("heartup", false, false, true, "MaxHeart", 6, 125, 150));
    level.pickUps.push_back(std::make_shared<MaxHeart>("heartup", false, false, true, "MaxHeart", 6, 175, 150));
    level.pickUps.push_back(std::make_shared<MaxHeart>("heartup", false, false, true, "MaxHeart", 6, 225, 150));

    levels.push_back(level);
}


void WorldMap::prepareLevel120() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=2;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall2x2"));
    level.walls.push_back(std::make_shared<Wall>(10,2,32,"wall2x8"));
    level.walls.push_back(std::make_shared<Wall>(0,7,32,"wall6x3"));

    //Enemies
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 3*32, 4*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 8*32, 4*32, 0.5, 3, 1));

    levels.push_back(level);
}

void WorldMap::prepareLevel020() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=2;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(10,2,32,"wall2x2"));
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall2x8"));
    level.walls.push_back(std::make_shared<Wall>(2,7,32,"wall6x3"));
    level.walls.push_back(std::make_shared<Wall>(11,7,32,"wall1x3"));

    //Enemies
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 3*32, 3*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 3*32, 5*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 6*32, 4*32, 0.5, 3, 1));


    levels.push_back(level);
}

void WorldMap::prepareLevel110() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=1;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall3x3"));
    //level.teleport = Teleport(4,2,32,"wall1x3"); //door
    level.walls.push_back(std::make_shared<Wall>(3,2,32,"wall1x3"));
    level.walls.push_back(std::make_shared<Wall>(4,2,32,"wall1x3"));

    level.walls.push_back(std::make_shared<Wall>(10,2,32,"wall2x8"));
    level.walls.push_back(std::make_shared<Wall>(0,8,32,"wall2x2"));

    //Enemies
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 5*32, 6*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 7*32, 3*32, 0.5, 3, 1));

    levels.push_back(level);
}

void WorldMap::prepareLevel010() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=1;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall2x8"));
    level.walls.push_back(std::make_shared<Wall>(2,2,32,"wall3x3"));
    //level.teleport = Teleport(5,2,32,"wall1x3"); //door
    level.walls.push_back(std::make_shared<Wall>(5,2,32,"wall1x3"));
    level.walls.push_back(std::make_shared<Wall>(6,2,32,"wall1x3"));

    level.walls.push_back(std::make_shared<Wall>(10,2,32,"wall2x3"));
    level.walls.push_back(std::make_shared<Wall>(10,8,32,"wall2x2"));

    //Enemies
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 4*32, 7*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 7*32, 7*32, 0.5, 3, 1));

    levels.push_back(level);
}

void WorldMap::prepareLevel100() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=1;
    level.levelCoordinate.y=0;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall12x2"));
    level.walls.push_back(std::make_shared<Wall>(10,4,32,"wall2x6"));
    level.walls.push_back(std::make_shared<Wall>(0,9,32,"wall5x1"));

    //Enemies
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 2*32, 5*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 2*32, 7*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 7*32, 5*32, 0.5, 3, 1));
    level.enemies.push_back(std::make_shared<Enemy>("shyguy", 7*32, 7*32, 0.5, 3, 1));

    levels.push_back(level);
}

void WorldMap::prepareLevel000() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=0;
    level.levelCoordinate.z=0;

    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"grass"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"wall12x2"));
    level.walls.push_back(std::make_shared<Wall>(0,4,32,"wall2x6"));
    level.walls.push_back(std::make_shared<Wall>(2,9,32,"wall5x1"));
    level.walls.push_back(std::make_shared<Wall>(10,9,32,"wall2x1"));

    //Dung
    level.walls.push_back(std::make_shared<Wall>(3,4,32,"dung2x3-left"));
    level.walls.push_back(std::make_shared<Wall>(5,4,32,"dung2x3-center-open")); //doors
    level.teleport = Teleport(5,6,32,"teleport1x2", 'D', 176,236); //doors
    level.walls.push_back(std::make_shared<Wall>(7,4,32,"dung2x3-right"));


    levels.push_back(level);
}

void WorldMap::prepareLevel00m1() {
    Level level;

    // Coordinate
    level.levelCoordinate.x=0;
    level.levelCoordinate.y=0;
    level.levelCoordinate.z=-1;
    //Floor
    level.floors.push_back(std::make_shared<Floor>(0,2,32,"dungeon-floor"));

    //Walls
    level.walls.push_back(std::make_shared<Wall>(0,2,32,"dung-wall-top"));
    level.walls.push_back(std::make_shared<Wall>(0,4,32,"dung-wall"));
    level.walls.push_back(std::make_shared<Wall>(10,4,32,"dung-wall"));
    level.walls.push_back(std::make_shared<Wall>(2,8,32,"dung-wall-bottom"));
    level.walls.push_back(std::make_shared<Wall>(4,9,32,"dung-tp"));
    level.teleport = Teleport(4,9,32,"teleport1x4", 'U', 174,232);
    level.walls.push_back(std::make_shared<Wall>(8,8,32,"dung-wall-bottom"));

    //Enemies
    level.enemies.push_back(std::make_shared<Enemy>("shyguy-boss", 5*32, 4*32, 0.5, 5, 2));


    levels.push_back(level);
}


