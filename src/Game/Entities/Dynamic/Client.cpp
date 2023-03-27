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
    ofSetColor(255, 255, 255);
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

int Client::payment()
{
    int cheese = this->burger->chosenIngredients["cheese"] * 3;
    int tomato = this->burger->chosenIngredients["tomato"] * 2;
    int lettuce = this->burger->chosenIngredients["lettuce"] * 2;
    int patty = this->burger->chosenIngredients["patty"] * 4;
    int money = 2 + cheese + tomato + lettuce + patty;
    return money;
}

int Client::serve(Burger *burger)
{
    int money = 0;
    if (this->burger->equals(burger))
    {
        this->isLeaving = true;
        money = this->payment();
    }
    else if (nextClient != nullptr)
        money = nextClient->serve(burger);
    return money;
}