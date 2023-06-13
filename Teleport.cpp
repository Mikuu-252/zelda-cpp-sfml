#include <iostream>
#include "Teleport.h"

//Private func
void Teleport::init() {

    sprite.setTexture(texture);
    sprite.setPosition(x*size, (y*size)-5);

}

void Teleport::loadTexture(std::string filename) {
    if (!texture.loadFromFile("../assets/world/" + filename + ".png")) {
        std::cerr << "Texture error for wall: " << filename << "\n";
    }
    else {
        std::cout << "Texture loaded successfully for teleport: " << filename << "\n";
        std::cout << "Texture size: " << texture.getSize().x << "x" << texture.getSize().y << "\n";
    }
}

//Public func
Teleport::Teleport(int x, int y, int size, std::string filename, char direction, int tpX, int tpY)
: x(x), y(y), size(size), filename(filename), direction(direction), tpX(tpX), tpY(tpY) {
    loadTexture(filename);
    init();
}

Teleport::Teleport() {}

//Draw
void Teleport::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

//Getter
const sf::Sprite &Teleport::getSprite() const {
    return sprite;
}

char Teleport::getDirection() const {
    return direction;
}

int Teleport::getTpX() const {
    return tpX;
}

int Teleport::getTpY() const {
    return tpY;
}

