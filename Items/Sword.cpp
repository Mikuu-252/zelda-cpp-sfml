
#include <iostream>
#include "Sword.h"

Sword::Sword(const std::string& filename, bool pickable, bool usable,bool purchasable , std::string tag, int x, int y, int value, int dmg, bool isActive)
        : Item(filename, pickable, usable, purchasable, tag, x, y, value), damage(dmg), isActive(isActive) {
    hide();
}

void Sword::show(int playerX, int playerY, int lastMove) {

    if(lastMove == 1) {
        sprite.setPosition(playerX, playerY-10);
        sprite.setRotation(0);
    } else if (lastMove == 2) {
        sprite.setPosition(playerX+32, playerY+40);
        sprite.setRotation(180);
    } else if (lastMove == 3) {
        sprite.setPosition(playerX-10, playerY+32);
        sprite.setRotation(270);
    } else {
        sprite.setPosition(playerX+40, playerY+10);
        sprite.setRotation(90);
    }

}

void Sword::hide() {
    sprite.setPosition(x, y);

}


bool Sword::getIsActive() const {
    return isActive;
}

void Sword::setIsActive(bool isActive) {
    Sword::isActive = isActive;
}


