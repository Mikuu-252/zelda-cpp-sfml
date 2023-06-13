

#ifndef PO23_SR17_252241_UI_H
#define PO23_SR17_252241_UI_H

#include <SFML/Graphics.hpp>

struct Heart {
    sf::Texture texture;
    sf::Sprite sprite;
};

struct Money {
    sf::Texture texture;
    sf::Sprite sprite;
};

class Ui {
    //Hearts
    Heart heart0;
    Heart heart1;
    Heart heart05;

    int maxHp;
    int hp;

    //Money
    Money money;
    sf::Font font;
    sf::Text moneyText;

    int moneyValue;

    void init();

public:
    Ui(int maxHp, int money);

    //Update
    void update(int maxHp, int hp, int money);

    //Draw
    void draw(sf::RenderWindow& window);
};


#endif //PO23_SR17_252241_UI_H
