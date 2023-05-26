#ifndef PO23_SR17_252241_WALL_H
#define PO23_SR17_252241_WALL_H


#include <SFML/Graphics.hpp>

class Wall {
private:
    sf::Texture texture;
    sf::Sprite sprite;
    int x;
    int y;
    int size;
    std::string filename;
    void loadTexture(std::string filename);
    void init();
public:
    Wall(int x, int y, int size, std::string filename);
    void draw(sf::RenderWindow& window);

    const sf::Sprite &getSprite() const;
};


#endif //PO23_SR17_252241_WALL_H
