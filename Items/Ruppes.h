

#ifndef PO23_SR17_252241_RUPPES_H
#define PO23_SR17_252241_RUPPES_H


#include "Item.h"

class Ruppes : public Item {

    int value;
    int x;
    int y;

public:
    Ruppes(const std::string &filename, bool isPickable, bool isUsable, std::string tag, int value, int x, int y);
    void draw(sf::RenderWindow &window);
    int pickUp() const;
};


#endif //PO23_SR17_252241_RUPPES_H

