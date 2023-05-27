#ifndef PO23_SR17_252241_WORLDMAP_H
#define PO23_SR17_252241_WORLDMAP_H

#include <vector>
#include "Wall.h"
#include "Floor.h"

struct Level{

    std::vector<Wall> walls;
    std::vector<Floor> floors;

};


class WorldMap {
    std::vector<Level> levels;
    int activeLevel = 0;
    void init();


    //Level func
    void prepareLevel130();
    void prepareLevel030();

public:
    WorldMap();
    const Level &getLevel() const;

public:
    void debugLevelInc();
};


#endif //PO23_SR17_252241_WORLDMAP_H
