// #include "LoseState.h"
#include "LoseState.h"

LoseState::LoseState()
{
	imgLose.load("images/LoseState.JPG");
}
void LoseState::tick()
{
}
void LoseState::render()
{
	ofSetColor(ofColor::white);
	imgLose.draw(0, 0, ofGetWidth(), ofGetHeight());
	string text = "I finally got the secret formula!!";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(text, ofGetWidth() / 2 - text.length() * 2, ofGetHeight() / 4 );
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