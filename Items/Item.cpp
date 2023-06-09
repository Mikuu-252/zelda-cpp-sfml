#include <iostream>
#include "Item.h"


Item::Item(const std::string& filename, bool pickable, bool usable, char tag) : filename(filename), pickable(pickable), usable(usable), tag(tag) {
    loadTexture();
}

Item::~Item() {

}

void Item::loadTexture() {
    if (!texture.loadFromFile("../assets/items/" + filename + ".png")) {
        std::cerr << "Texture error for item: " << filename << "\n";
    }
    sprite.setTexture(texture);
}

char Item::getTag() const {
    return tag;
}

const sf::Sprite &Item::getSprite() const {
    return sprite;
}

void Item::draw(sf::RenderWindow &window) {

}

bool Item::isPickable() const {
    return pickable;
}

bool Item::isUsable() const {
    return usable;
}

int Item::pickUp() const{
    return 0;
}


