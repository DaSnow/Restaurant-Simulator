// #include "Inspector.h"

// Inspector::Inspector(int x, int y, int width, int height, ofImage sprite, Burger *burger) : Entity(x, y, width, height, sprite)
// {
//     this->burger = burger;
// }
// Inspector::~Inspector()
// {
//     delete burger;
// }
// void Inspector::render()
// {
//     ofSetColor(255, 255, 255);
//     burger->render();
//     ofSetColor(255, 255 * (patience / originalPatience), 255 * (patience / originalPatience));
//     sprite.draw(x, y, width, height);
//     if (nextClient != nullptr)
//     {
//         nextClient->render();
//     }
// }

// void Inspector::tick()
// {
//     patience--;
//     burger->setY(y);
//     if (patience == 0)
//     {
//         InspectorIsLeaving = true;
//     }
//     if (nextClient != nullptr)
//     {
//         nextClient->tick();
//     }
// }

// int Inspector::payment()
// {
//     int cheese = this->burger->chosenIngredients["cheese"] * 3;
//     int tomato = this->burger->chosenIngredients["tomato"] * 2;
//     int lettuce = this->burger->chosenIngredients["lettuce"] * 2;
//     int patty = this->burger->chosenIngredients["patty"] * 4;
//     int money = 2 + cheese + tomato + lettuce + patty;
//     return money;
// }

// int Inspector::serve(Burger *burger)
// {
//     int money = 0;
//     if (this->burger->equals(burger))
//     {
//         this->isLeaving = true;
//         money = this->payment();
//     }
//     else if (nextClient != nullptr)
//         money = nextClient->serve(burger);
//     return money;
// }