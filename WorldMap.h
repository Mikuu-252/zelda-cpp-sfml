#ifndef PO23_SR17_252241_WORLDMAP_H
#define PO23_SR17_252241_WORLDMAP_H

#include <vector>
#include "Wall.h"
#include "Floor.h"

struct LevelCoordinate {
    int x;
    int y;
    int z;
};
struct Level{
    LevelCoordinate levelCoordinate;
    std::vector<Wall> walls;
    std::vector<Floor> floors;

};


class WorldMap {
    std::vector<Level> levels;
    LevelCoordinate activeLevel;
    void init();


    //Level func
    void prepareLevel0();
    void prepareLevel130();
    void prepareLevel030();

public:
    WorldMap();
    const Level &getLevel() const;
    void debugLevel();
};


#endif //PO23_SR17_252241_WORLDMAP_H
