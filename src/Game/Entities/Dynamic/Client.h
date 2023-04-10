#pragma once
#include "Entity.h"
#include "Burger.h"

class Client : public Entity
{
private:
    float originalPatience = 2000;

public:
    Burger *burger;
    int patience = 2000;
    Client(int, int, int, int, ofImage, Burger *);
    virtual ~Client();
    void tick();
    void render();
    int serve(Burger *);
    int payment();
    Client *nextClient = nullptr;
    bool isLeaving = false;
    int getPatience() { return patience; }
};