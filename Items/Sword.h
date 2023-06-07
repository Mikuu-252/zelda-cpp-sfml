
#ifndef PO23_SR17_252241_SWORD_H
#define PO23_SR17_252241_SWORD_H


#include "Item.h"

class Sword : public Item {
private:
    int damage;
    bool isActive;

public:
    Sword(const std::string& filename, bool isPickable, bool isUsable, int dmg, bool isActive);

    void show(int playerX, int playerY, int lastMove);
    void hide();
    void draw(sf::RenderWindow& window);

    bool getIsActive() const;
    void setIsActive(bool isActive);

};


#endif //PO23_SR17_252241_SWORD_H
