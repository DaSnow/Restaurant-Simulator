#include "Entity.h"
#include "Burger.h"

class Client : public Entity
{
private:
    Burger *burger;
    float originalPatience = 2000;

public:
    int patience = 2000;
    Client(int, int, int, int, ofImage, Burger *);
    virtual ~Client();
    void tick();
    void render();
    int serve(Burger *);
    Client *nextClient = nullptr;
    bool isLeaving = false;
};