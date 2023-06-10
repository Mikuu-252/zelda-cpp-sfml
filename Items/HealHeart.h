

#ifndef PO23_SR17_252241_HEALHEART_H
#define PO23_SR17_252241_HEALHEART_H


#include "Item.h"

class HealHeart : public Item {

public:
    HealHeart(const std::string &filename, bool pickable, bool usable, bool purchasable, std::string tag, int value, int x, int y);

    int pickUp() const;

};


#endif //PO23_SR17_252241_HEALHEART_H
