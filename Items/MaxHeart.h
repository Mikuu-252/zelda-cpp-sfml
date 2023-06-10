

#ifndef PO23_SR17_252241_MAXHEART_H
#define PO23_SR17_252241_MAXHEART_H


#include "Item.h"

class MaxHeart : public Item {

public:
    MaxHeart(const std::string &filename, bool pickable, bool isable, bool purchasable, std::string tag, int value, int x, int y);

    int pickUp() const;

};


#endif //PO23_SR17_252241_MAXHEART_H
