

#include <iostream>
#include "Enemy.h"

Enemy::Enemy(const std::string &filename, int x, int y, float speed, int maxHp, int dmg)
        :filename(filename), x(x), y(y),speed(speed),maxHp(maxHp), dmg(dmg) {
    loadTexture();
    init();
}

void Enemy::loadTexture() {
    if (!texture.loadFromFile("../assets/entity/" + filename + ".png")) {
        std::cerr << "Texture error for item: " << filename << "\n";
    }
    sprite.setTexture(texture);
}

void Enemy::init() {

    hp = maxHp;

    //Animation
    frameNumber = 4;
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
    sprite.setPosition(x, y);
}

void Enemy::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Enemy::update() {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= speed;
        lastMove = 1;
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += speed;
        lastMove = 2;
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= speed;
        lastMove = 3;
    } else
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += speed;
        lastMove = 4;
    }

    move(movement);
    anim(movement);

}

void Enemy::negativeUpdate() {
    sf::Vector2f movement(0.f, 0.f);

    if (lastMove == 1) {
        movement.y += speed;
    } else
    if (lastMove == 2) {
        movement.y -= speed;
    } else
    if (lastMove == 3) {
        movement.x += speed;
    } else
    if (lastMove == 4) {
        movement.x -= speed;
    }

    move(movement);
}

void Enemy::move(sf::Vector2f movement) {
    sprite.move(movement);
}

void Enemy::anim(sf::Vector2f movement) {

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


const sf::Sprite &Enemy::getSprite() const {
    return sprite;
}

int Enemy::getImmortalFrames() const {
    return immortalFrames;
}

void Enemy::setImmortalFrames(int immortalFrames) {
    Enemy::immortalFrames = immortalFrames;
}

int Enemy::getMaxImmortalFrames() const {
    return maxImmortalFrames;
}

void Enemy::setMaxImmortalFrames(int maxImmortalFrames) {
    Enemy::maxImmortalFrames = maxImmortalFrames;
}

void Enemy::takeDmg(int dmg) {
    hp -= dmg;
}

int Enemy::getMaxHp() const {
    return maxHp;
}

void Enemy::setHp(int hp) {
    Enemy::hp = hp;
}

int Enemy::getDmg() const {
    return dmg;
}

int Enemy::getHp() const {
    return hp;
}
