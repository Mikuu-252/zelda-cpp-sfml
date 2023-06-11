#ifndef PO23_SR17_252241_ITEM_H
#define PO23_SR17_252241_ITEM_H


#include <SFML/Graphics.hpp>

class Item {

protected:
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Font font;
    std::string filename;

    bool pickable;
    bool usable;
    bool purchasable;
    std::string tag;
    int x;
    int y;
    int value;

    void loadTexture();

public:
    Item(const std::string& filename, bool pickable, bool usable, bool purchasable, std::string tag, int x, int y, int value);
    virtual ~Item();


    const sf::Sprite &getSprite() const;
    std::string getTag() const;
    bool isPickable() const;
    bool isUsable() const;
    bool isPurchasable() const;
    int getValue() const;


    void setPickable(bool pickable);
    void setPurchasable(bool purchasable);

    virtual int pickUp() const;
    virtual void draw(sf::RenderWindow& window);


};


#endif //PO23_SR17_252241_ITEM_H
