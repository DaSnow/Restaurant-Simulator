//
// Created by joshu on 11/3/2020.
//

#include "Restaurant.h"
#include "EntityManager.h"
#include "Inspector.h"

Player *Restaurant::getPlayer() { return player; }
void Restaurant::setPlayer(Player *player) { this->player = player; }

Restaurant::Restaurant()
{
    floor.load("images/Wood.jpg");
    entityManager = new EntityManager();
    ofImage chefPlayerImage;
    seats.load("images/seatsss.png");
    seats.resize(150, 100);

    eating.load("images/seat_with_people.png");
    eating.resize(150, 200);
    eatingg.push_back(eating);

    boat.load("images/boat.png");
    boat.resize(150, 125);
    jellyFish.load("images/jellyFish.png");
    jellyFish.resize(65, 70);
    chefPlayerImage.load("images/moving.PNG");
    initItems();
    initCounters();
    initClients();
    generateClient();
    this->player = new Player(0, 600, 64, 64, chefPlayerImage, entityManager);
}
void Restaurant::initItems()
{
    ofImage burgerSpriteSheet, cheeseImg, lettuceImg, tomatoImg, burgerImg, botBreadImg, topBreadImg, plateImg;
    burgerSpriteSheet.load("images/burger.png");
    topBreadImg.cropFrom(burgerSpriteSheet, 25, 16, 112, 43);   // top bun
    burgerImg.cropFrom(burgerSpriteSheet, 30, 134, 103, 48);    // patty
    cheeseImg.cropFrom(burgerSpriteSheet, 169, 213, 102, 39);   // cheese
    tomatoImg.cropFrom(burgerSpriteSheet, 169, 158, 110, 41);   // tomato
    lettuceImg.cropFrom(burgerSpriteSheet, 161, 62, 117, 34);   // lettuce
    botBreadImg.cropFrom(burgerSpriteSheet, 444, 270, 115, 39); // bottom bun
    plateImg.cropFrom(burgerSpriteSheet, 575, 263, 131, 51);    // plate

    cheese = new Item(cheeseImg, "cheese");
    RandomItem.push_back(cheese);

    lettuce = new Item(lettuceImg, "lettuce");
    RandomItem.push_back(lettuce);

    tomato = new Item(tomatoImg, "tomato");
    RandomItem.push_back(tomato);

    burger = new Item(burgerImg, "patty");
    RandomItem.push_back(burger);

    botBread = new Item(botBreadImg, "bottomBun");
    topBread = new Item(topBreadImg, "topBun");
}
void Restaurant::initCounters()
{
    int counterWidth = 96;
    int yOffset = 500;
    ofImage counterSheet, plateCounterImg, cheeseCounterImg, stoveCounterImg, lettuceCounterImg, emptyCounterImg, tomatoCounterImg, breadCounterImg;
    counterSheet.load("images/kitchen_cabinets_by_ayene_chan.png");
    stoveCounterImg.cropFrom(counterSheet, 224, 12, 32, 43);  // stoveTop
    lettuceCounterImg.cropFrom(counterSheet, 96, 76, 32, 43); // Vegetables
    emptyCounterImg.cropFrom(counterSheet, 0, 245, 30, 43);   // Empty
    tomatoCounterImg.cropFrom(counterSheet, 96, 200, 32, 48); // fruit basket
    cheeseCounterImg.cropFrom(counterSheet, 64, 73, 32, 46);  // cheese
    plateCounterImg.cropFrom(counterSheet, 0, 133, 32, 50);   // plates
    breadCounterImg.cropFrom(counterSheet, 0, 63, 34, 56);    // buns
    entityManager->addEntity(new BaseCounter(0, yOffset - 16, counterWidth, 117, nullptr, plateCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth, yOffset - 7, counterWidth, 108, cheese, cheeseCounterImg));
    entityManager->addEntity(new StoveCounter(counterWidth * 2, yOffset, counterWidth, 102, burger, stoveCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 3, yOffset, counterWidth, 102, lettuce, lettuceCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 4, yOffset, counterWidth, 102, nullptr, emptyCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 5, yOffset - 10, counterWidth, 113, tomato, tomatoCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 6, yOffset - 32, counterWidth, 133, botBread, breadCounterImg));
    entityManager->addEntity(new BaseCounter(counterWidth * 7, yOffset - 32, counterWidth, 133, topBread, breadCounterImg));
}
void Restaurant::initClients()
{
    ofImage temp;

    temp.load("images/People/Squidward.PNG");
    people.push_back(temp);
    temp.load("images/People/Sandy.png");
    people.push_back(temp);
    temp.load("images/People/Pluff.PNG");
    people.push_back(temp);
    temp.load("images/People/Pearl.png");
    people.push_back(temp);
    temp.load("images/People/Patrick.png");
    people.push_back(temp);
    temp.load("images/People/Larry.png");
    people.push_back(temp);
    temp.load("images/People/Krabs.PNG");
    people.push_back(temp);
    temp.load("images/People/Gary.PNG");
    people.push_back(temp);

    // ANADIR A LA ULTIMA POSICION DEL VECTOR (PEOPLE) EL INSPECTOR
    temp.load("images/People/Inspector.png");
    people.push_back(temp);
}
void Restaurant::tick()
{
    ticks++;
    if (entityManager->InspectorDisappointment != entityManager->LastInspectorDisappointment)
    {
        money /= 2;
        entityManager->LastInspectorDisappointment = entityManager->InspectorDisappointment;
    }

    if (ticks % 400 == 0)
    {
        generateClient();
        // eatingg->tick();
    }
    player->tick();
    entityManager->tick();
    if (entityManager->Disappointment >= 10)
    {
        lose = true;
    }
}

void Restaurant::generateClient()
{

    Burger *b = new Burger(72, 100, 50, 25);
    b->addIngredient(botBread);

    int limit = ofRandom(1, 4);
    Item *randIngre;
    for (int i = 0; i < limit; i++)
    {
        randIngre = RandomItem[ofRandom(0, 4)];
        b->addIngredient(randIngre);
    }
    b->addIngredient(topBread);

    // int RandomClient = ofRandom(0, 9);
    if (count != 10) {
        count += 1;
        entityManager->addClient(new Client(0, 50, 64, 72, people[ofRandom(0,8)], b));
        
    } else {
        entityManager->addClient(new Inspector(0, 50, 64, 72, people[8], b));
        count = 1;
    }
}
void Restaurant::render()
{
    floor.draw(0, 0, ofGetWidth(), ofGetHeight());
    ofSetColor(ofColor::white);

    eating.draw(ofGetWidth() / 4, (ofGetHeight() / 6) - 50);
    eating.draw(ofGetWidth() / 4, (ofGetHeight() / 6) * 2);
    eating.draw(ofGetWidth() / 4 * 2, (ofGetHeight() / 6) - 50);
    eating.draw(ofGetWidth() / 4 * 2, (ofGetHeight() / 6) * 2);

    boat.draw(ofGetWidth() - boat.getWidth(), (ofGetHeight() / 3));

    jellyFish.draw(ofGetWidth() - jellyFish.getWidth(), (ofGetHeight() / 8));

    player->render();
    entityManager->render();
    ofSetColor(255, 255, 255);
    ofDrawBitmapString("Money: " + to_string(money), ofGetWidth() / 2, 10);
    ofSetColor(256, 256, 256);
}
void Restaurant::serveClient()
{
    money += entityManager->firstClient->serve(player->getBurger());

    if (money >= 100)
    {
        win = true;
    }
}
void Restaurant::keyPressed(int key)
{
    player->keyPressed(key);
    if (key == 'e') // Removes money per ingredients if greater than 0
        money -= (money > 0) ? 1 : 0;
    if (key == 's' && player->burger->ingredients.size() > 0)
    {
        serveClient();
        player->burger->trashBurger(); // Throws out burger
    }
}
void Restaurant::keyReleased(int key)
{
    player->keyReleased(key);
}