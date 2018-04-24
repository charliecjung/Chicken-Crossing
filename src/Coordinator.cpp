#include "Player.h"
#include "Coordinator.h"
#include "Enemy.h"

#include "ofxGui.h"
//--------------------------------------------------------------


// This is Coordinator loading all of the game sprites and sound files.

void Coordinator::setup() {
	//Cited from:
	// https://github.com/vanderlin/ofxBox2d/blob/master/example-ContactListener/src/ofApp.h

	box2d.init();
	box2d.enableEvents();
	box2d.createGround();
	box2d.setFPS(60.0);
	box2d.registerGrabbing();

	//add listeners
	ofAddListener(box2d.contactStartEvents, this, &Coordinator::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &Coordinator::contactEnd);




	player_.setup();

	


	
	backgroundImage_.load("images/images/backgroundImage.png");

	SoundPlayer_.load("music/backgroundMusic.flac");

	
	testEnemy_.setup();
	SoundPlayer_.setLoop(true);
	SoundPlayer_.play();

}

// RM's update() method. Obsolete as draw() seems to be superior at this point.

//--------------------------------------------------------------
void Coordinator::update() {

	testEnemy_.setX(testEnemy_.getX() + kEnemySpeed);
}
// Cited from:
// https://forum.openframeworks.cc/t/background-image-in-openframeworks-app/11731

// draw() is helpful for drawing sprites on the screen in a timely fashion.
// I am using the default settings that are provided for now and will see if I can
// fine tune it to adjust gameplay.

//--------------------------------------------------------------
void Coordinator::draw() {
	glPolygonMode(GL_BACK, GL_FILL);
	backgroundImage_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	glPolygonMode(GL_FRONT, GL_FILL);

	ofDrawBitmapString("X: " + ofToString(player_.getX()), 400, 600);
	ofDrawBitmapString("Y: " + ofToString(player_.getY()), 600, 800);
	 
	player_.draw();
	testEnemy_.draw();

}

//--------------------------------------------------------------

// Citing from:
// https://forum.openframeworks.cc/t/call-keypressed-in-draw-function/12880/2

// This handles the key presses of the arrow keys for the movement of the frog.

void Coordinator::keyPressed(int key) {
	if (key == OF_KEY_UP) {
		player_.MoveUp();
	}
	else if (key == OF_KEY_LEFT) {
		player_.MoveLeft();
	}
	else if (key == OF_KEY_RIGHT) {
		player_.MoveRight();
	}
	else if (key == OF_KEY_DOWN) {
		player_.MoveDown();
	}
	else if (key == 'p') {
		ofToggleFullscreen();

	}
	else {
		std::cout << "Cannot understand your next movement. Please try again." << std::endl;
	}
}

//--------------------------------------------------------------
void Coordinator::keyReleased(int key) {

}

//--------------------------------------------------------------
void Coordinator::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void Coordinator::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void Coordinator::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void Coordinator::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void Coordinator::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void Coordinator::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void Coordinator::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void Coordinator::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void Coordinator::dragEvent(ofDragInfo dragInfo) {

}
void Coordinator::EndGame() {

}
// Future implementation of when the player dies.
void Coordinator::KillPlayer() {

}

