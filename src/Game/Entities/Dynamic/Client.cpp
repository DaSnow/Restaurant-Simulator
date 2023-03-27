#include "Client.h"

Client::Client(int x, int y, int width, int height, ofImage sprite, Burger *burger) : Entity(x, y, width, height, sprite)
{
    this->burger = burger;
}
Client::~Client()
{
    delete burger;
}
void Client::render()
{
    ofSetColor(255,255,255);
    burger->render();
    ofSetColor(255, 255 * (patience / originalPatience), 255 * (patience / originalPatience));
    sprite.draw(x, y, width, height);
    if (nextClient != nullptr)
    {
        nextClient->render();
    }
}

void Client::tick()
{
    patience--;
    burger->setY(y);
    if (patience == 0)
    {
        isLeaving = true;
    }
    if (nextClient != nullptr)
    {
        nextClient->tick();
    }
}

int Client::serve(Burger *burger)
{
    int money = 0;
    if (this->burger->equals(burger))
    {
        this->isLeaving = true;
        money = 10;
    }
    else if (nextClient != nullptr)
        money = nextClient->serve(burger);
    return money;
}