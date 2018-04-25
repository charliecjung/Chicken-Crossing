#include "Player.h"
#include "Coordinator.h"
#include "Enemy.h"
#include "ofMain.h"
#include "ofxGui.h"
//--------------------------------------------------------------


// This is Coordinator loading all of the game sprites and sound files.

void Coordinator::setup() {
	player_.setup();
	
	backgroundImage_.load("images/images/backgroundImage.png");

	SoundPlayer_.load("music/backgroundMusic.flac");

	// (int newX, int newY, int newWidth, int newHeight, int newSpeed, int newSpeedMultiplier);

	testEnemy_ = new Enemy(900, 900, 200, 200, -20, 0);
	SoundPlayer_.setLoop(true);
	SoundPlayer_.play();

}

// RM's update() method. Obsolete as draw() seems to be superior at this point.

//--------------------------------------------------------------
void Coordinator::update() {
	doOverlap(player_.getX(), player_.getY(), (player_.getX() + player_.getWidth()), (player_.getY() + player_.getHeight()), testEnemy_->getX(), testEnemy_->getY(), (testEnemy_->getX() + testEnemy_->getWidth()), (testEnemy_->getY() + testEnemy_->getHeight()));
	
	
	
}
// Cited from:
// https://forum.openframeworks.cc/t/background-image-in-openframeworks-app/11731

// draw() is helpful for drawing sprites on the screen in a timely fashion.
// I am using the default settings that are provided for now and will see if I can
// fine tune it to adjust gameplay.

//--------------------------------------------------------------
void Coordinator::draw() {
	//doOverlap(player_.getX(), player_.getY(), (player_.getX() + player_.getWidth()), (player_.getY() + player_.getHeight()), testEnemy_->getX(), testEnemy_->getY(), (testEnemy_->getX() + testEnemy_->getWidth()), (testEnemy_->getY() + testEnemy_->getHeight()));
	glPolygonMode(GL_BACK, GL_FILL);
	backgroundImage_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	glPolygonMode(GL_FRONT, GL_FILL);
	ofDrawBitmapString("Player X: " + ofToString(player_.getX()), 400, 600);
	ofDrawBitmapString("Player Y: " + ofToString(player_.getY()), 800, 600);
	ofDrawBitmapString("testEnemy X: " + ofToString(testEnemy_->getX()), 400, 800);
	ofDrawBitmapString("testEnemy Y: " + ofToString(testEnemy_->getY()), 800, 800);

	player_.draw();
	testEnemy_->draw();

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
	
	else if (key == OF_KEY_ESC) {
		delete testEnemy_;
		testEnemy_ = NULL;
		std::exit(0);
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

//
// Referenced from:
// https://www.geeksforgeeks.org/find-two-rectangles-overlap/

// l1: Top Left coordinate of first rectangle.
// r1: Bottom Right coordinate of first rectangle.
// l2 : Top Left coordinate of second rectangle.
// r2 : Bottom Right coordinate of second rectangle.


// Cited for intersection of two rectangle's logic:
// https://www.geeksforgeeks.org/find-two-rectangles-overlap/
bool Coordinator::doOverlap(int leftX1, int leftY1, int rightX1, int rightY1, int leftX2, int leftY2, int rightX2, int rightY2) {
	
	/*
	if (leftX1 > rightX2 || leftX2 > rightX1) {
		//ofSetColor(255, 0, 0);
		glPolygonMode(GL_FRONT, GL_FILL);
		ofDrawBitmapString("Not Intersecting", 100, 100);
		
		return false;
	}

	if (leftY1 < rightY2 || leftY2 < rightY1) {
		
		glPolygonMode(GL_FRONT, GL_FILL);
		ofDrawBitmapString("Not Intersecting!", 200, 200);
		
		return false;
	}
	*/
	if ((leftX1 > rightX2 || leftX2 > rightX1) || (leftY1 > rightY2 || leftY2 > rightY1)) {
		//std::exit(0);
		glPolygonMode(GL_FRONT, GL_FILL);
		ofDrawBitmapString("Not Intersecting!", 200, 200);

		return false;
	}
	delete testEnemy_;
	testEnemy_ = NULL;
	std::exit(0);
	glPolygonMode(GL_FRONT, GL_FILL);
	ofDrawBitmapString("Intersecting!", 300, 300);
	return true;
}

