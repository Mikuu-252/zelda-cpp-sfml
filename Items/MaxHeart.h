

#ifndef PO23_SR17_252241_MAXHEART_H
#define PO23_SR17_252241_MAXHEART_H


#include "Item.h"

class MaxHeart : public Item {

    int value;
    int x;
    int y;

public:
    MaxHeart(const std::string &filename, bool isPickable, bool isUsable, std::string tag, int value, int x, int y);
    void draw(sf::RenderWindow &window);
    int pickUp() const;

};


#endif //PO23_SR17_252241_MAXHEART_H
