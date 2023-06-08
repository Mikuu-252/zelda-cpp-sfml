#ifndef PO23_SR17_252241_WORLDMAP_H
#define PO23_SR17_252241_WORLDMAP_H

#include <vector>
#include "Wall.h"
#include "Floor.h"
#include "Teleport.h"

struct LevelCoordinate {
    int x;
    int y;
    int z;
};
struct Level{
    LevelCoordinate levelCoordinate;
    std::vector<Wall> walls;
    std::vector<Floor> floors;
    Teleport teleport;
};


class WorldMap {
    std::vector<Level> levels;
    LevelCoordinate activeLevel;
    void init();


    //Level func
    void prepareLevel0();

    void prepareLevel130();
    void prepareLevel030();
    void prepareLevel03m1();

    void prepareLevel120();
    void prepareLevel020();

    void prepareLevel110();
    void prepareLevel010();

    void prepareLevel100();
    void prepareLevel000();

public:
    WorldMap();
    const Level &getLevel() const;
    void debugLevel();
    void changeActiveLevel(int x, int y, int z);
};


#endif //PO23_SR17_252241_WORLDMAP_H
