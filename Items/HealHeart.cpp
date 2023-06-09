

#include "HealHeart.h"

HealHeart::HealHeart(const std::string &filename, bool isPickable, bool isUsable, std::string tag, int value, int x, int y)
        : Item(filename, isPickable, isUsable, tag), value(value), x(x), y(y) {
    sprite.setPosition(x, y);
}

void HealHeart::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

int HealHeart::pickUp() const {
    return value;
}