#ifndef PO23_SR17_252241_ITEM_H
#define PO23_SR17_252241_ITEM_H


#include <SFML/Graphics.hpp>

class Item {

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    std::string filename;

public:
    bool isPurchasable() const;

protected:
    bool pickable;
    bool usable;
    bool purchasable;
    std::string tag;
    int x;
    int y;
    int value;


public:
    Item(const std::string& filename, bool pickable, bool usable, bool purchasable, std::string tag, int x, int y, int value);
    virtual ~Item();

    const sf::Sprite &getSprite() const;
    std::string getTag() const;
    bool isPickable() const;
    bool isUsable() const;

    void loadTexture();
    virtual int pickUp() const;

    virtual void draw(sf::RenderWindow& window);

    void setPickable(bool pickable);

    int getValue() const;

    void setPurchasable(bool purchasable);

};


#endif //PO23_SR17_252241_ITEM_H
