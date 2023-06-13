
#ifndef PO23_SR17_252241_SWORD_H
#define PO23_SR17_252241_SWORD_H


#include "Item.h"

class Sword : public Item {

private:
    int damage;
    bool isActive;

public:
    Sword(const std::string& filename, bool pickable, bool usable,bool purchasable , std::string tag, int x, int y, int value, int dmg, bool isActive);

    //Update
    void show(int playerX, int playerY, int lastMove);
    void hide();

    //Getter
    int getDamage() const;
    bool getIsActive() const;

    //Setter
    void setIsActive(bool isActive);


};


#endif //PO23_SR17_252241_SWORD_H
