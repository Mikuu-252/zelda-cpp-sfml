
#include <iostream>
#include "floor.h"

Floor::Floor(int x, int y, int size, std::string filename): x(x), y(y), size(size), filename(filename) {
    loadTexture(filename);
    init();
}

void Floor::loadTexture(std::string filename) {
    if (!texture.loadFromFile("assets/" + filename + ".png")) {
        std::cerr << "Texture error for wall: " << filename << "\n";
    }
    else {
        std::cout << "Texture loaded successfully for floor: " << filename << "\n";
        std::cout << "Texture size: " << texture.getSize().x << "x" << texture.getSize().y << "\n";
    }
}

void Floor::init() {

    sprite.setTexture(texture);
    sprite.setPosition(x*size, y*size);

}

void Floor::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

const sf::Sprite &Floor::getSprite() const {
    return sprite;
}
