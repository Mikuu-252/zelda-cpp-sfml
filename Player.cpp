#include <iostream>
#include "Player.h"

Player::Player() {
    loadTexture();
    init();
}

void Player::loadTexture() {
    if (!texture.loadFromFile("assets/character.png")) {
        std::cerr << "Texture error \n";
    }

    int textureWidth = texture.getSize().x / 4;
    int textureHeight = texture.getSize().y;
    for (int i = 0; i < 4; i++) {
        textureDirection[i] = sf::IntRect(i * textureWidth, 0, textureWidth, textureHeight);
    }
}

void Player::init() {
    //Texture
    sprite.setTexture(texture);
    sprite.setTextureRect(textureDirection[0]);
    sprite.setPosition(360, 240);

    //Player
    playerSpeed = 1;
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

    if (movement.x < 0.f) {
        sprite.setTextureRect(textureDirection[1]);
    }
    else if (movement.x > 0.f) {
        sprite.setTextureRect(textureDirection[2]);
    }
    else if (movement.y < 0.f) {
        sprite.setTextureRect(textureDirection[3]);
    }
    else if (movement.y > 0.f) {
        sprite.setTextureRect(textureDirection[0]);
    }
}


