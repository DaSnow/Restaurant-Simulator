//
// Created by joshu on 11/4/2020.
//
#pragma once

#include "Entity.h"
#include "Item.h"

class Burger
{
private:
  int x, y, width, height;

public:
  vector<Item *> ingredients;
  map<string, int> chosenIngredients = {
      {"patty", 0},
      {"tomato", 0},
      {"lettuce", 0},
      {"cheese", 0}};
  Burger(int, int, int, int);
  void addIngredient(Item *item);
  void removeIngredient();
  void render();
  void clear();
  void setY(int y)
  {
    this->y = y;
  }
  bool equals(Burger *borgar);
};