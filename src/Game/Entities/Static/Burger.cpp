//
// Created by joshu on 11/4/2020.
//

#include "Burger.h"

Burger::Burger(int x, int y, int width, int height)
{
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
}

void Burger::addIngredient(Item *item)
{
    ingredients.push_back(item);
    if (item->name == "patty")
        chosenIngredients["patty"]++;
    else if (item->name == "cheese")
        chosenIngredients["cheese"]++;
    else if (item->name == "lettuce")
        chosenIngredients["lettuce"]++;
    else if (item->name == "tomato")
        chosenIngredients["tomato"]++;
}

void Burger::render()
{
    int counter = 1;
    for (Item *ingredient : ingredients)
    {
        ingredient->sprite.draw(x - 5, y - (counter * 10) + 55, width * 0.70, height * 0.70);
        counter++;
    }
}

void Burger::clear()
{
    ingredients.empty();
}

bool Burger::equals(Burger *borgar)
{
    if (ingredients.size() == 0 || ingredients[0]->name != "bottomBun")
        return false;
    if (ingredients[ingredients.size() - 1]->name != "topBun")
        return false;
    for (int i = 1; i < borgar->ingredients.size() - 1; i++)
    {
        bool exist = false;
        int count = 0;
        for (int z = 1; z < ingredients.size() - 1; z++)
        {
            if (ingredients[z]->name == borgar->ingredients[i]->name)
            {
                exist = true;
                count++;
            }
        }
        if (!exist || count != chosenIngredients[ingredients[i]->name])
            return false;
    }
    return true;
}

void Burger::removeIngredient()
{
    if (ingredients.size() > 0)
        ingredients.pop_back();
}