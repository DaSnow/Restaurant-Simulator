#pragma once
#include "Animation.h"
#include "Burger.h"
#include "EntityManager.h"
#include "BaseCounter.h"
#include "StoveCounter.h"
class Player : public Entity
{

private:
    int speed = 0;
    int cookCount = 0; // counter to call cookBurger() function each frame under the right condition
    bool cook = false;
    string facing = "right";
    Animation *chefAnim;
    StoveCounter *stove;
    EntityManager *entityManager;

public:
    Burger *burger;
    Player(int x, int y, int width, int height, ofImage sprite, EntityManager *em);
    void tick();
    void render();
    void keyPressed(int);
    void keyReleased(int);
    void mousePressed(int, int, int);
    void setFacing(string);
    BaseCounter *getActiveCounter();
    Burger *getBurger()
    {
        return burger;
    }
};