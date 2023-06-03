#include <iostream>
#include "Item.h"


Item::Item(const std::string& filename, bool isPickable, bool isUsable) : filename(filename), isPickable(isPickable), isUsable(isUsable) {
    loadTexture();
}


void Item::loadTexture() {
    if (!texture.loadFromFile("../assets/items/" + filename + ".png")) {
        std::cerr << "Texture error for item: " << filename << "\n";
    }
    sprite.setTexture(texture);
}

const sf::Sprite &Item::getSprite() const {
    return sprite;
}
