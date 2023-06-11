

#ifndef PO23_SR17_252241_ENEMY_H
#define PO23_SR17_252241_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy {
protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string filename;

    sf::IntRect animDown[4];
    sf::IntRect animLeft[4];
    sf::IntRect animUp[4];
    sf::IntRect animRight[4];

    //Stat
    int x;
    int y;
    float speed;
    int maxHp;
    int dmg;
    int hp;
    int lastMove;
    int immortalFrames = 0;
    int maxImmortalFrames = 8;

    //Anim
    int frameNumber;
    int animNumber;
    int animSpeed;
    sf::Clock clock;


    void init();
    void loadTexture();
    void anim(sf::Vector2f movement);
    void move(sf::Vector2f movement);

public:
    Enemy(const std::string &filename, int x, int y, float speed, int maxHp, int dmg);
    virtual void draw(sf::RenderWindow& window);
    void update();
    void negativeUpdate();

    int getMaxHp() const;

    int getHp() const;

    const sf::Sprite &getSprite() const;
    int getImmortalFrames() const;
    int getMaxImmortalFrames() const;

    void setHp(int hp);
    void setImmortalFrames(int immortalFrames);
    void setMaxImmortalFrames(int maxImmortalFrames);
    void takeDmg(int dmg);

    int getDmg() const;


};


#endif //PO23_SR17_252241_ENEMY_H
