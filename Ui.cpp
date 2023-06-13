#include <iostream>
#include "Ui.h"

//Private func
void Ui::init() {
    //Font
    if (!font.loadFromFile("../assets/ui/arial.ttf"))
    {
        std::cerr << "Font error arial \n";
    }

    //Hearts
    if (!heart0.texture.loadFromFile("../assets/ui/heart0.png")) {
        std::cerr << "Texture error heart0 \n";
    }
    heart0.sprite.setTexture(heart0.texture);

    if (!heart1.texture.loadFromFile("../assets/ui/heart1.png")) {
        std::cerr << "Texture error heart1 \n";
    }
    heart1.sprite.setTexture(heart1.texture);

    if (!heart05.texture.loadFromFile("../assets/ui/heart05.png")) {
        std::cerr << "Texture error heart05 \n";
    }
    heart05.sprite.setTexture(heart05.texture);

    hp = maxHp;

    //Money
    if (!money.texture.loadFromFile("../assets/ui/money-icon.png")) {
        std::cerr << "Texture error money \n";
    }
    money.sprite.setTexture(money.texture);
    money.sprite.setPosition(354, 0);
    moneyText.setFont(font);
    moneyText.setFillColor(sf::Color::White);
    moneyText.setCharacterSize(16);
    moneyText.setPosition(364,0);
}

//Public func
Ui::Ui(int maxHp, int money): maxHp(maxHp), moneyValue(money) {
    init();
}

//Update
void Ui::update(int maxHp, int hp, int money) {
    this->maxHp = maxHp;
    this->hp = hp;
    this->moneyValue = money;
}

//Draw
void Ui::draw(sf::RenderWindow &window) {

    //Heart draw
    int hpMaxIndex = maxHp;
    int hpIndex = hp;
    int x = 0;
    int y = 0;

    while (!(hpMaxIndex == 0)) {
        if(hpIndex >= 2) {
            heart1.sprite.setPosition(x,y);
            window.draw(heart1.sprite);

            hpMaxIndex -= 2;
            hpIndex -= 2;
        } else if (hpIndex == 1) {
            heart05.sprite.setPosition(x,y);
            window.draw(heart05.sprite);

            hpMaxIndex -= 2;
            hpIndex -= 1;
        } else {
            heart0.sprite.setPosition(x,y);
            window.draw(heart0.sprite);

            hpMaxIndex -= 2;
        }
        x += 32;
        if(x == 192) {
            x = 0;
            y += 32;
        }
    }

    //Money draw

    moneyText.setString(std::to_string(moneyValue));
    window.draw(money.sprite);
    window.draw(moneyText);
}
