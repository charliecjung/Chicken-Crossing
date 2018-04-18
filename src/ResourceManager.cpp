#include "ResourceManager.h"
#include "Player.h"

#include "ofxGui.h"
//--------------------------------------------------------------
void ResourceManager::setup() {
	player_.setUp();
	backgroundImage_.load("images/images/backgroundImage.png");
	frogUp_.load("images/frog/FROG_UP.png");
	frogLeft_.load("images/frog/FROG_LEFT.png");
	frogRight_.load("images/frog/FROG_RIGHT.png");
	frogDown_.load("images/frog/FROG_DOWN.png");
	currentImage_.load("images/frog/FROG_UP.png");
	SoundPlayer_.load("music/backgroundMusic.flac");
	SoundPlayer_.setLoop(true);
	SoundPlayer_.play();
	
}

//--------------------------------------------------------------
void ResourceManager::update() {
}
// Cited from:
// https://forum.openframeworks.cc/t/background-image-in-openframeworks-app/11731

//--------------------------------------------------------------
void ResourceManager::draw() {
	glPolygonMode(GL_BACK, GL_FILL);
	backgroundImage_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	glPolygonMode(GL_FRONT, GL_FILL);

	// ofDrawBitmapString("X: " + ofToString(player_.getX()), 400, 600);
	// ofDrawBitmapString("Y: " + ofToString(player_.getY()), 600, 800);

	currentImage_.draw(player_.getX(), player_.getY(), player_.getWidth(), player_.getHeight());
	if (player_.getY() <= 0) {
		std::exit(0);
    }
}

//--------------------------------------------------------------

// Citing from:
// https://forum.openframeworks.cc/t/call-keypressed-in-draw-function/12880/2

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
	else if (key == 'p') {
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
    // Future implementation of when the player dies.
void ResourceManager::killPlayer() {

}
void ResourceManager:: moveLeft() {

	// Case for left edge of screen

	currentImage_ = frogLeft_;
	int futureXPos = player_.getX() - player_.getSize();
	if (player_.getX() > 0) {
		player_.setX(futureXPos);

	}
	else if (futureXPos <= 0) {
		player_.setX(0);
	}
}
void ResourceManager::moveRight() {

	// Case for right edge of screen

	currentImage_ = frogRight_;
	int futureXPos = player_.getX() + player_.getSize();
	if (futureXPos < (ofGetWindowWidth() - (player_.getSize()*2 ))) {
		player_.setX(futureXPos);
	}
	else if (futureXPos >= (ofGetWindowWidth() - (player_.getSize() * 2))) {
		player_.setX((ofGetWindowWidth() - (player_.getSize() * 2)));
	}

}
void ResourceManager::moveUp() {

	// Case for top edge of screen

	currentImage_ = frogUp_;
	int futureYPos = player_.getY() - player_.getSize();
	if (futureYPos > 0) {
		player_.setY(futureYPos);
	}
	else if (futureYPos <= 0) {
		player_.setY(0);
	}

}
void ResourceManager::moveDown() {
	currentImage_ = frogDown_;

	// Case for bottom edge of screen

	int futureYPos = player_.getY() + player_.getSize();
	if (futureYPos < (ofGetWindowHeight() - (player_.getSize() * 2))) {
		player_.setY(futureYPos);
	}
	else if (futureYPos >= (ofGetWindowHeight() - (player_.getSize() * 2))) {
		player_.setY((ofGetWindowHeight() - (player_.getSize() * 2)));
	}
}
