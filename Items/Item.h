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

    //Update
    virtual int pickUp() const;

    //Draw
    virtual void draw(sf::RenderWindow& window);

    //Getter
    const sf::Sprite &getSprite() const;
    std::string getTag() const;
    bool isPickable() const;
    bool isUsable() const;
    bool isPurchasable() const;
    int getValue() const;

    //Setter
    void setPickable(bool pickable);
    void setPurchasable(bool purchasable);

};


#endif //PO23_SR17_252241_ITEM_H
