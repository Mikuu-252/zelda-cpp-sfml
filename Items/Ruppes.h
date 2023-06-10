

#ifndef PO23_SR17_252241_RUPPES_H
#define PO23_SR17_252241_RUPPES_H


#include "Item.h"

class Ruppes : public Item {

public:
    Ruppes(const std::string &filename, bool pickable, bool usable, bool purchasable, std::string tag, int value, int x, int y);

    int pickUp() const;
};


#endif //PO23_SR17_252241_RUPPES_H

