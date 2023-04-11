// #include "MenuState.h"
#include "WinState.h"

WinState::WinState() {
	imgWin.load("images/WinState.JPG");
}
void WinState::tick() {
}
void WinState::render() {
	ofSetColor(ofColor::white);
	imgWin.draw(0, 0, ofGetWidth(), ofGetHeight());
	string text = "Won";
	ofSetColor(0,0,0);
	ofDrawBitmapString(text, ofGetWidth() / 2, ofGetHeight() / 2);
}

void WinState::keyPressed(int key){
	
}

void WinState::mousePressed(int x, int y, int button){
}

void WinState::reset(){
	setFinished(false);
	setNextState("");
}