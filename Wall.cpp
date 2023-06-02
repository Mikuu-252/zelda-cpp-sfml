#include <iostream>
#include "Wall.h"


Wall::Wall(int x, int y, int size, std::string filename): x(x), y(y), size(size), filename(filename) {
    loadTexture(filename);
    init();
}

void Wall::loadTexture(std::string filename) {
    if (!texture.loadFromFile("../assets/world/" + filename + ".png")) {
        std::cerr << "Texture error for wall: " << filename << "\n";
    }
    else {
        std::cout << "Texture loaded successfully for wall: " << filename << "\n";
        std::cout << "Texture size: " << texture.getSize().x << "x" << texture.getSize().y << "\n";
    }
}

void Wall::init() {

    sprite.setTexture(texture);
    sprite.setPosition(x*size, y*size);

}

void Wall::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

const sf::Sprite &Wall::getSprite() const {
    return sprite;
}
