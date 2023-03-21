// #include "MenuState.h"
#include "WinState.h"

WinState::WinState() {
}
void WinState::tick() {
}
void WinState::render() {
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