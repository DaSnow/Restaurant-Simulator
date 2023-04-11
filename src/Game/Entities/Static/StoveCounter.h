#pragma once
#include "BaseCounter.h"

class StoveCounter : public BaseCounter
{
private:
    // Item *item;
    int cookCount = 0;
public:
    int r = 255;
    int g = 255;
    int b = 255;
    StoveCounter(int x, int y, int width, int height, Item *item, ofImage sprite);
    // Item *getItem();
    void cookBurger();
    void fadeBrown();
    void showItemth();
};