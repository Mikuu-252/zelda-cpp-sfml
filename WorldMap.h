#ifndef PO23_SR17_252241_WORLDMAP_H
#define PO23_SR17_252241_WORLDMAP_H

#include <vector>
#include <memory>
#include "Wall.h"
#include "Floor.h"
#include "Teleport.h"
#include "Items/Item.h"

struct LevelCoordinate {
    int x;
    int y;
    int z;
};
struct Level{
    LevelCoordinate levelCoordinate;
    //std::vector<Wall> walls;
    //std::vector<Floor> floors;
    Teleport teleport;
    std::vector<std::shared_ptr<Wall>> walls;
    std::vector<std::shared_ptr<Floor>> floors;
    std::vector<std::shared_ptr<Item>> pickUps;
};


class WorldMap {
    std::vector<Level> levels;
    LevelCoordinate activeLevel;
    void init();


    //Level func
    void prepareLevelDebug();

    void prepareLevel130();
    void prepareLevel030();
    void prepareLevel03m1();

    void prepareLevel120();
    void prepareLevel020();

    void prepareLevel110();
    void prepareLevel010();

    void prepareLevel100();
    void prepareLevel000();
    void prepareLevel00m1();

public:
    WorldMap();
    const Level &getLevel() const;
    void debugLevel();
    void changeActiveLevel(int x, int y, int z);
};


#endif //PO23_SR17_252241_WORLDMAP_H
