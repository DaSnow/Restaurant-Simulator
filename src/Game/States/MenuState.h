#pragma once

#include "State.h"
#include "Button.h"

class MenuState : public State
{
private:
	ofImage img1;
	ofImage imgText;
	bool instuctions = false;
	Button *startButton;
	Button *instuctionButton;
	Button *commandsButton;

public:
	MenuState();
	void tick();
	void render();
	void keyPressed(int key);
	void mousePressed(int x, int y, int button);
	void reset();
};
