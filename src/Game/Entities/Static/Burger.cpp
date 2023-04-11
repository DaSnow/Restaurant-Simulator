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
    if (borgar->ingredients[0]->name != "bottomBun")
        return false;
    if (borgar->ingredients[borgar->ingredients.size() - 1]->name != "topBun")
        return false;
    for (unsigned int i = 1; i < ingredients.size() - 1; i++)
    {
        bool exist = false;
        int count = 0;
        for (unsigned int z = 1; z < borgar->ingredients.size() - 1; z++)
        {
            if (borgar->ingredients[z]->name == ingredients[i]->name)
            {
                exist = true;
                count++;
            }
            if (borgar->ingredients[z]->name == "bottomBun" || borgar->ingredients[z]->name == "topBun")
                return false;
        }
        if (!exist || count != borgar->chosenIngredients[ingredients[i]->name])
            return false;
    }
    return true;
}

void Burger::removeIngredient()
{
    if (ingredients.size() > 0)
        ingredients.pop_back();
}

void Burger::trashBurger()
{
    ingredients.clear();
    chosenIngredients.clear();
}