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
    int maxHp;


    int immortalFrames = 0;
    int maxImmortalFrames = 60;

    //Func
    void loadTexture();

    void init();
    void playerAnim(sf::Vector2f movement);
    void playerMove(sf::Vector2f movement);

public:
    Player();
    void reset();

    //Draw
    void draw(sf::RenderWindow& window);

    //Update
    void negativeUpdate();
    void update();
    void changeLevelPos();

    //Getter
    const sf::Sprite &getSprite() const;
    int getLastMove() const;
    int getMaxHp() const;
    int getHp() const;
    int getMoney() const;
    int getImmortalFrames() const;
    int getMaxImmortalFrames() const;

    //Setter
    void setPosition(int x, int y);
    void setMaxHp(int maxHp);
    void setHp(int hp);
    void setMoney(int money);
    void setImmortalFrames(int immortalFrames);
    void takeDmg(int dmg);




};


#endif //PO23_SR17_252241_PLAYER_H
