#include <iostream>
#include "Player.h"

Player::Player() {
    loadTexture();
    init();
}

void Player::loadTexture() {
    if (!texture.loadFromFile("../assets/entity/character.png")) {
        std::cerr << "Texture error player \n";
    }
}

void Player::init() {
    //Player
    playerSpeed = 2;
    lastMove = 2;
    money = 5;
    maxHp = 6;
    hp = 6;

    //Animation
    frameNumber = 9;
    animNumber = 4;
    animSpeed = 20;

    int textureWidth = texture.getSize().x / frameNumber;
    int textureHeight = texture.getSize().y / animNumber;
    for (int i = 0; i < animNumber; i++) {
        for (int j = 0; j < frameNumber; ++j) {
            switch (i) {
                case 0:
                    animDown[j] = sf::IntRect(j * textureWidth, i * textureHeight, textureWidth, textureHeight);
                    break;
                case 1:
                    animLeft[j] = sf::IntRect(j * textureWidth, i * textureHeight, textureWidth, textureHeight);
                    break;
                case 2:
                    animRight[j] = sf::IntRect(j * textureWidth, i * textureHeight, textureWidth, textureHeight);
                    break;
                case 3:
                    animUp[j] = sf::IntRect(j * textureWidth, i * textureHeight, textureWidth, textureHeight);
                    break;
            }
        }
    }

    //Texture
    sprite.setTexture(texture);
    sprite.setTextureRect(animDown[0]);
    sprite.setPosition(256, 192);

}

int Player::getMoney() const {
    return money;
}

void Player::setMoney(int money) {
    Player::money = money;
}

int Player::getHp() const {
    return hp;
}

void Player::setHp(int hp) {
    Player::hp = hp;
}

void Player::update() {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= playerSpeed;
        lastMove = 1;
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += playerSpeed;
        lastMove = 2;
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= playerSpeed;
        lastMove = 3;
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += playerSpeed;
        lastMove = 4;
    }

    playerMove(movement);
    playerAnim(movement);

}

void Player::negativeUpdate() {
    sf::Vector2f movement(0.f, 0.f);

    if (lastMove == 1) {
        movement.y += playerSpeed;
    } else
    if (lastMove == 2) {
        movement.y -= playerSpeed;
    } else
    if (lastMove == 3) {
        movement.x += playerSpeed;
    } else
    if (lastMove == 4) {
        movement.x -= playerSpeed;
    }

    playerMove(movement);
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::playerMove(sf::Vector2f movement) {
    sprite.move(movement);
}

void Player::playerAnim(sf::Vector2f movement) {

    int frameIndex = 0;
    sf::Time currentTime = clock.getElapsedTime();
    frameIndex = static_cast<int>(currentTime.asSeconds() * animSpeed) % frameNumber;

    if (movement.x < 0.f) {
        sprite.setTextureRect(animLeft[frameIndex]);
    }
    else if (movement.x > 0.f) {
        sprite.setTextureRect(animRight[frameIndex]);
    }
    else if (movement.y < 0.f) {
        sprite.setTextureRect(animUp[frameIndex]);
    }
    else if (movement.y > 0.f) {
        sprite.setTextureRect(animDown[frameIndex]);
    }
}

const sf::Sprite &Player::getSprite() const {
    return sprite;
}

int Player::getLastMove() const {
    return lastMove;
}

void Player::changeLevelPos() {
    int x = sprite.getPosition().x;
    int y = sprite.getPosition().y;

    if (lastMove == 1) {
        sprite.setPosition(x, 320-34);
    }
    if (lastMove == 2) {
        sprite.setPosition(x, 78);
    }
    if (lastMove == 3) {
        sprite.setPosition(384-34, y);;
    }
    if (lastMove == 4) {
        sprite.setPosition(34, y);
    }
}

void Player::setPosition(int x, int y) {
    sprite.setPosition(x, y);
}

int Player::getMaxHp() const {
    return maxHp;
}

void Player::setMaxHp(int maxHp) {
    Player::maxHp = maxHp;
}
