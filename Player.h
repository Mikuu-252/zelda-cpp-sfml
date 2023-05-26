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
    int lastMove;

    int frameNumber;
    int animNumber;
    int animSpeed;
    sf::Clock clock;


    void loadTexture();
    void init();
    void playerAnim(sf::Vector2f movement);
    void playerMove(sf::Vector2f movement);

public:
    const sf::Sprite &getSprite() const;
    Player();
    void draw(sf::RenderWindow& window);

    void negativeUpdate();
    void update();
};


#endif //PO23_SR17_252241_PLAYER_H
