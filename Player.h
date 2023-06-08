#ifndef PO23_SR17_252241_PLAYER_H
#define PO23_SR17_252241_PLAYER_H

#include <SFML/Graphics.hpp>


class Player {

private:
    //SFML
    sf::Texture texture;
    sf::Sprite sprite;
    sf::IntRect animDown[9];
    sf::IntRect animLeft[9];
    sf::IntRect animUp[9];
    sf::IntRect animRight[9];

    //Move
    float playerSpeed;
    int lastMove;

    //Anim
    int frameNumber;
    int animNumber;
    int animSpeed;
    sf::Clock clock;

    //Stats
    int money;
    int hp;
public:
    int getMaxHp() const;

    void setMaxHp(int maxHp);

private:
    int maxHp;

    //Func
    void loadTexture();

    void init();
    void playerAnim(sf::Vector2f movement);
    void playerMove(sf::Vector2f movement);

public:
    Player();

    //Draw
    void draw(sf::RenderWindow& window);

    //Getter
    const sf::Sprite &getSprite() const;
    int getLastMove() const;

    //Setter
    void setPosition(int x, int y);

    //Update
    void negativeUpdate();
    void update();
    void changeLevelPos();

    int getMoney() const;

    void setMoney(int money);

    int getHp() const;

    void setHp(int hp);

};


#endif //PO23_SR17_252241_PLAYER_H
