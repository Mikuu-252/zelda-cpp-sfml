#ifndef PO23_SR17_252241_ITEM_H
#define PO23_SR17_252241_ITEM_H


#include <SFML/Graphics.hpp>

class Item {

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string filename;

    bool isPickable;
    bool isUsable;

public:
    Item(const std::string& filename, bool isPickable, bool isUsable);

    const sf::Sprite &getSprite() const;

    void loadTexture();

};


#endif //PO23_SR17_252241_ITEM_H
