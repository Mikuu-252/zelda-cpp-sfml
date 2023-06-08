#ifndef PO23_SR17_252241_TELEPORT_H
#define PO23_SR17_252241_TELEPORT_H


#include <SFML/Graphics.hpp>

class Teleport {

private:
    sf::Texture texture;
    sf::Sprite sprite;
    int x;
    int y;
    int size;
    std::string filename;
    char direction;
    int tpX;
    int tpY;

    void loadTexture(std::string filename);
    void init();


public:
    Teleport(int x, int y, int size, std::string filename, char direction, int tpX, int tpY);

    Teleport();

    void draw(sf::RenderWindow& window);

    const sf::Sprite &getSprite() const;

    char getDirection() const;

    int getTpX() const;

    int getTpY() const;


};


#endif //PO23_SR17_252241_TELEPORT_H
