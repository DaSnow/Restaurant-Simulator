#include "MenuState.h"

MenuState::MenuState() {
	string text = "Start";
	startButton = new Button(ofGetWidth()/2 - 20, ofGetHeight()/2 + 20, 64, 50, "Start");
	// startButton = new Button(ofGetWidth()/2 - text.length()*8, ofGetHeight()/2 - text.length()*11, 64, 50, "Start");
	instuctionButton = new Button(ofGetWidth()/6 - text.length()*8, ofGetHeight()/4 + ( (ofGetHeight()/4) * 2) - text.length()*11, 64, 50, "HELOOOOOOOOOOO");
	img1.load("images/Krusty_Burger.png");
	imgText.load("images/textcopy.png");
}
void MenuState::tick() {
	startButton->tick();
	instuctionButton->tick();
	if(instuctionButton->wasPressed()){
		instuctions = true;
		render();
	} else if(instuctions && startButton->wasPressed()){
		setNextState("Game");
		setFinished(true);
	}
}
void MenuState::render() {
	ofSetColor(ofColor::white);
	img1.draw(0, 0, ofGetWidth(), ofGetHeight());
	// floor.draw(0, 0, ofGetWidth(), ofGetHeight());
	
	// ofSetBackgroundColor(230, 230, 250);
	ofSetColor(ofColor::white);
	instuctionButton->render();
	// startButton->render();
	ofSetColor(ofColor::white);
	if(instuctions){
		imgText.draw(ofGetWidth()/4, ofGetHeight()/3, ofGetWidth() * 0.60, ofGetHeight() * 0.25);
	}
	
}

void MenuState::keyPressed(int key){
	
}

void MenuState::mousePressed(int x, int y, int button){
	instuctionButton->mousePressed(x, y);
	startButton->mousePressed(x, y);
	// instuctions = true;
}

void MenuState::reset(){
	setFinished(false);
	setNextState("");
	startButton->reset();
}