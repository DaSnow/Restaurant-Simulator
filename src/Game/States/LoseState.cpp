// #include "LoseState.h"
#include "LoseState.h"

LoseState::LoseState()
{
}
void LoseState::tick()
{
}
void LoseState::render()
{
	string text = "Lose";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(text, ofGetWidth() / 2, ofGetHeight() / 2);
}

void LoseState::keyPressed(int key)
{
}

void LoseState::mousePressed(int x, int y, int button)
{
}

void LoseState::reset()
{
	setFinished(false);
	setNextState("");
}