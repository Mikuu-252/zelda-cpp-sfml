#include <iostream>
#include "Item.h"


Item::Item(const std::string& filename, bool pickable, bool usable, bool purchasable, std::string tag, int x, int y, int value)
          : filename(filename), pickable(pickable), usable(usable), purchasable(purchasable), tag(tag),x(x),y(y), value(value) {
    loadTexture();

    //Font
    if (!font.loadFromFile("../assets/ui/arial.ttf"))
    {
        std::cerr << "Font error arial \n";
    }

}

Item::~Item() {

}

void Item::loadTexture() {
    if (!texture.loadFromFile("../assets/items/" + filename + ".png")) {
        std::cerr << "Texture error for item: " << filename << "\n";
    }
    sprite.setTexture(texture);
}

std::string Item::getTag() const {
    return tag;
}

const sf::Sprite &Item::getSprite() const {
    return sprite;
}

void Item::draw(sf::RenderWindow &window) {
    if(!purchasable){
        window.draw(sprite);
    } else {
        window.draw(sprite);

        sf::Text textValue;
        textValue.setFont(font);
        textValue.setString(std::to_string(value));
        textValue.setCharacterSize(18);
        textValue.setPosition(x+3,y+20);

        window.draw(textValue);
    }
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

void Item::setPickable(bool pickable) {
    Item::pickable = pickable;
}

int Item::getValue() const {
    return value;
}

bool Item::isPurchasable() const {
    return purchasable;
}

void Item::setPurchasable(bool purchasable) {
    Item::purchasable = purchasable;
}


