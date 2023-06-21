
#ifndef PO23_SR17_252241_SWORD_H
#define PO23_SR17_252241_SWORD_H


#include "Item.h"

class Sword : public Item {

private:
    int damage;
    bool isActive;
    int swordCd = 16;
    int swordMaxCd = 16;

    int showTime = 8;
    int maxShowTime = 8;

public:
    Sword(const std::string& filename, bool pickable, bool usable,bool purchasable , std::string tag, int x, int y, int value, int dmg, bool isActive);

    //Update
    void show(int playerX, int playerY, int lastMove);
    void hide();

    //Getter
    int getDamage() const;
    bool getIsActive() const;
    int getSwordCd() const;
    int getSwordMaxCd() const;
    int getShowTime() const;
    int getMaxShowTime() const;

    //Setter
    void setIsActive(bool isActive);
    void setSwordCd(int swordCd);
    void setShowTime(int showTime);

};


#endif //PO23_SR17_252241_SWORD_H
