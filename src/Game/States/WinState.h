#include "State.h"
// #include "Restaurant.h"

class WinState : public State
{
public:
    ofImage imgWin;
    WinState();
    void reset();
    void tick();
    void render();
    void keyPressed(int key);
    void mousePressed(int x, int y, int button);
    // void keyReleased(int key);
};