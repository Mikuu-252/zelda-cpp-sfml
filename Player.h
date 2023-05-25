#ifndef PO23_SR17_252241_PLAYER_H
#define PO23_SR17_252241_PLAYER_H

#include <SFML/Graphics.hpp>


class Player {
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect animDown[9];
    sf::IntRect animLeft[9];
    sf::IntRect animUp[9];
    sf::IntRect animRight[9];

    float playerSpeed;

    int frameNumber;
    int animNumber;
    int animSpeed;
    sf::Clock clock;


    void loadTexture();
    void init();
    void playerMove();
    void playerAnim(sf::Vector2f movement);

public:
    Player();
    void update();
    void draw(sf::RenderWindow& window);
};


#endif //PO23_SR17_252241_PLAYER_H
