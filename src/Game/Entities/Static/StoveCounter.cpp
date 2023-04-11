#include "StoveCounter.h"

StoveCounter::StoveCounter(int x, int y, int width, int height, Item *item, ofImage sprite) : BaseCounter(x, y, width, height, item, sprite)
{
    // this->item = item;
}

// Item *StoveCounter::getItem()
// {
//     return item;
// }

void StoveCounter::cookBurger() // counts down ticks to cook
{
    if (cookCount < 20)
    {
        cookCount += 1;
        fadeBrown();
    }
    else
    {
        cookCount = 0;
        item->cooked = true;
    }
}

void StoveCounter::fadeBrown() // changes rbg values
{
    r -= 5;
    g -= 9;
    b -= (b > 0) ? 13 : 0;
    showItemth();
}

void StoveCounter::showItemth()
{
    if (item != nullptr)
    {
        ofSetColor(r, g, b);
        item->sprite.draw(x + width / 2 - 25, y - 30, 50, 30);
    }
}