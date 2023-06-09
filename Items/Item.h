#ifndef PO23_SR17_252241_ITEM_H
#define PO23_SR17_252241_ITEM_H


#include <SFML/Graphics.hpp>

class Item {

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    std::string filename;

    bool pickable;
    bool usable;
    char tag;

public:
    bool isPickable() const;
    bool isUsable() const;

public:
    Item(const std::string& filename, bool pickable, bool usable, char tag);
    virtual ~Item();

    const sf::Sprite &getSprite() const;
    void loadTexture();
    virtual void draw(sf::RenderWindow& window);
    virtual int pickUp() const;

    char getTag() const;
};


#endif //PO23_SR17_252241_ITEM_H
