

#include "MaxHeart.h"

MaxHeart::MaxHeart(const std::string &filename, bool isPickable, bool isUsable, std::string tag, int value, int x, int y)
        : Item(filename, isPickable, isUsable, tag), value(value), x(x), y(y) {
    sprite.setPosition(x, y);
}

void MaxHeart::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

int MaxHeart::pickUp() const {
    return value;
}