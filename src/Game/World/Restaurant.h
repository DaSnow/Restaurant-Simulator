//
// Created by joshu on 11/3/2020.
//
#pragma once

#include "BaseCounter.h"
#include "EntityManager.h"
#include "Player.h"
#include "ofMain.h"

class Restaurant
{
private:
    EntityManager *entityManager;
    int ticks = 0;
    std::vector<ofImage> people;
    int money = 0;

public:
    Player *player;
    bool win = false;
    bool lose = false;
    Restaurant();
    Player *getPlayer();
    void setPlayer(Player *player);
    Item *cheese;
    Item *lettuce;
    Item *tomato;
    Item *burger;
    Item *botBread;
    Item *topBread;
    ofImage floor;
    void initItems();
    void initCounters();
    void initClients();
    void generateClient();
    void serveClient();
    void tick();
    void render();
    void keyPressed(int key);
    void keyReleased(int key);
};
