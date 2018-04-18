#include "ResourceManager.h"
#include "Player.h"
#include "ofxGui.h"
//--------------------------------------------------------------
void ResourceManager::setup() {
	frogUp.load("images/FROG/FROG_UP.png");
	frogLeft.load("images/FROG/FROG_LEFT.png");
	frogRight.load("images/FROG/FROG_RIGHT.png");
	frogDown.load("images/FROG/FROG_DOWN.png");
	currentImage.load("images/FROG/FROG_UP.png");
	//backgroundImage.load("images/backgroundImage.png");
}

//--------------------------------------------------------------
void ResourceManager::update() {
	//currentImage.draw(player_.getX(), player_.getY(), player_.getWidth(), player_.getHeight());
	
}

//--------------------------------------------------------------
void ResourceManager::draw() {
	currentImage.draw(player_.getX(), player_.getY(), player_.getWidth(), player_.getHeight());
	
}

//--------------------------------------------------------------

//Citing from:
//https://forum.openframeworks.cc/t/call-keypressed-in-draw-function/12880/2
void ResourceManager::keyPressed(int key) {
	if (key == OF_KEY_UP) {
		moveUp();
	}
	else if (key == OF_KEY_LEFT) {
		moveLeft();
	}
	else if (key == OF_KEY_RIGHT) {
		moveRight();
	}
	else if (key == OF_KEY_DOWN) {
		moveDown();
	}
	else if (key == 'P') {
		ofToggleFullscreen();

	}
	else {
		std::cout << "Cannot understand your next movement. Please try again." << std::endl;
	}
}

//--------------------------------------------------------------
void ResourceManager::keyReleased(int key) {

}

//--------------------------------------------------------------
void ResourceManager::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ResourceManager::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ResourceManager::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ResourceManager::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ResourceManager::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ResourceManager::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ResourceManager::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ResourceManager::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ResourceManager::dragEvent(ofDragInfo dragInfo) {

}
void ResourceManager::endGame() {

}

void ResourceManager::killPlayer() {

}
void ResourceManager:: moveLeft() {
	//Case for left edge of screen
	currentImage = frogLeft;
	int futureXPos = player_.getX() - player_.getSize();
	if (player_.getX() > 0) {
		player_.setX(futureXPos);

	}
	else if (futureXPos <= 0) {
		player_.setX(0);
	}
}
void ResourceManager::moveRight() {
	//Case for right edge of screen
	currentImage = frogRight;
	int futureXPos = player_.getX() + player_.getSize();
	if (futureXPos < (ofGetWindowWidth() - (player_.getSize()*2 ))) {
		player_.setX(futureXPos);
	}
	else if (futureXPos >= (ofGetWindowWidth() - (player_.getSize() * 2))) {
		player_.setX((ofGetWindowWidth() - (player_.getSize() * 2)));
	}

}
void ResourceManager::moveUp() {
	//Case for top edge of screen
	currentImage = frogUp;
	int futureYPos = player_.getY() - player_.getSize();
	if (futureYPos > 0) {
		player_.setY(futureYPos);
	}
	else if (futureYPos <= 0) {
		player_.setY(0);
	}

}
void ResourceManager::moveDown() {
	currentImage = frogDown;
	//Case for bottom edge of screen
	int futureYPos = player_.getY() + player_.getSize();
	if (futureYPos < (ofGetWindowHeight() - (player_.getSize() * 2))) {
		player_.setY(futureYPos);
	}
	else if (futureYPos >= (ofGetWindowHeight() - (player_.getSize() * 2))) {
		player_.setY((ofGetWindowHeight() - (player_.getSize() * 2)));
	}
}
