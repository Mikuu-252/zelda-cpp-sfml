#ifndef PO23_SR17_252241_PLAYER_H
#define PO23_SR17_252241_PLAYER_H

#include <SFML/Graphics.hpp>


class Player {
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect textureDirection[4];
    float playerSpeed;


    void loadTexture();
    void init();
    void playerMove();

public:
    Player();
    void update();
    void draw(sf::RenderWindow& window);
};


#endif //PO23_SR17_252241_PLAYER_H
