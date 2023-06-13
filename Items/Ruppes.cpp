#include "Ruppes.h"

Ruppes::Ruppes(const std::string &filename, bool pickable, bool usable, bool purchasable, std::string tag, int value, int x, int y)
    : Item(filename, pickable, usable, purchasable, tag, x, y, value) {
    sprite.setPosition(x, y);
}


int Ruppes::pickUp() const {
    return value;
}
