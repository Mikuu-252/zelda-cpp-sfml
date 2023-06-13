

#ifndef PO23_SR17_252241_FLOOR_H
#define PO23_SR17_252241_FLOOR_H

#include <SFML/Graphics.hpp>

class Floor {
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
    Floor(int x, int y, int size, std::string filename);
    void draw(sf::RenderWindow& window);

    //Getter
    const sf::Sprite &getSprite() const;
};


#endif //PO23_SR17_252241_FLOOR_H
