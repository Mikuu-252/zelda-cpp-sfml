#include <iostream>
#include "Player.h"

Player::Player() {
    loadTexture();
    init();
    clock.restart();
}

void Player::loadTexture() {
    if (!texture.loadFromFile("assets/character.png")) {
        std::cerr << "Texture error \n";
    }
}

void Player::init() {
    //Player
    playerSpeed = 1;

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
    sprite.setPosition(360, 240);

}

void Player::update() {
    playerMove();
}

void Player::draw(sf::RenderWindow& window) {
    window.draw(sprite);
}

void Player::playerMove() {
    sf::Vector2f movement(0.f, 0.f);

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        movement.y -= playerSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        movement.y += playerSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        movement.x -= playerSpeed;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        movement.x += playerSpeed;
    }

    sprite.move(movement);

    playerAnim(movement);
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

