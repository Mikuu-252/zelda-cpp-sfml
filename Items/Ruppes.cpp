

#include <iostream>
#include "Ruppes.h"

Ruppes::Ruppes(const std::string &filename, bool isPickable, bool isUsable, char tag, int value, int x, int y)
    : Item(filename, isPickable, isUsable, tag), value(value), x(x), y(y) {
    sprite.setPosition(x, y);
}

void Ruppes::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

int Ruppes::pickUp() const {
    return value;
}
