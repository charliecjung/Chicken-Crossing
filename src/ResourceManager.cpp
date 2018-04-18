#include "ResourceManager.h"
#include "Player.h"

#include "ofxGui.h"
//--------------------------------------------------------------


// This is ResourceManager loading all of the game sprites and sound files.

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

// RM's update() method. Obsolete as draw() seems to be superior at this point.

//--------------------------------------------------------------
void ResourceManager::update() {
}
// Cited from:
// https://forum.openframeworks.cc/t/background-image-in-openframeworks-app/11731

// draw() is helpful for drawing sprites on the screen in a timely fashion.
// I am using the default settings that are provided for now and will see if I can
// fine tune it to adjust gameplay.

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

// This handles the key presses of the arrow keys for the movement of the frog.

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

//To Preface This:
// I did some game-testing because I suspected that the ofGetWindowWidth() and ofGetWindowHeight() were actually bigger than 
// the screen by a small number of pixels (<~10)... so I was able to display the values of screenWidth and screenHeight using
// ofDrawLine() and was able to make calculations based off of feel.

// Another note is that I chose ResourceManager to handle the implementation for move and then hand it off to Player when a key is
// pressed. 

// This is because I wanted to "sanitize" or check the input of the Player so they aren't changing their x/y position by like
// 1000 pixels or able to escape the boundaries by modifying my edge cases.

//This way player movement is consistent through all the Player objects


void ResourceManager:: moveLeft() {

    // Case for left edge of screen

    // update sprite's image
	currentImage_ = frogLeft_;

    // futureXPos is x coord + body of sprite.

	int futureXPos = player_.getX() - player_.getSize();
	if (player_.getX() > 0) {

        // if the future position is to the right of the left boundary, then update position

		player_.setX(futureXPos);

	}
	else if (futureXPos <= 0) {

        // if we are going out of the screen then trap the player to the left most position.

		player_.setX(0);
	}
}
void ResourceManager::moveRight() {

    // Case for right edge of screen

    //update sprite image

	currentImage_ = frogRight_;

    //updated futureXPos

	int futureXPos = player_.getX() + player_.getSize();
	if (futureXPos < (ofGetWindowWidth() - (player_.getSize()*2 ))) {
        // This was a tricky edge case where I realized that for the player + body of sprite to touch the boundary of the 
        // visible screen was actually screenWidth - 100. Therefore, I got the screenWidth - (2*sizeofSprite): sizeOfSprite = 50;

		player_.setX(futureXPos);
	}
	else if (futureXPos >= (ofGetWindowWidth() - (player_.getSize() * 2))) {

        // This logic is if the player is beyond the boundary then trap the player within the screen.

		player_.setX((ofGetWindowWidth() - (player_.getSize() * 2)));
	}

}
void ResourceManager::moveUp() {

    // Case for top edge of screen

    // update Sprite position

	currentImage_ = frogUp_;
    
    //update futureYPos

	int futureYPos = player_.getY() - player_.getSize();

    // if the sprite is below the top edge of the screen

	if (futureYPos > 0) {
		player_.setY(futureYPos);
	}
    // if the sprite is beyond the screen, trap it within!

	else if (futureYPos <= 0) {
		player_.setY(0);
	}

}
void ResourceManager::moveDown() {
	currentImage_ = frogDown_;

	// Case for bottom edge of screen

    //update futureYPos

	int futureYPos = player_.getY() + player_.getSize();

    // This was a tricky edge case where I realized that for the player + body of sprite to touch the boundary of the 
    // visible screen was actually screenWidth - 100. Therefore, I got the screenWidth - (2*sizeofSprite): sizeOfSprite = 50;

	if (futureYPos < (ofGetWindowHeight() - (player_.getSize() * 2))) {
		player_.setY(futureYPos);
	}

    //Same logic applies down below.

	else if (futureYPos >= (ofGetWindowHeight() - (player_.getSize() * 2))) {
		player_.setY((ofGetWindowHeight() - (player_.getSize() * 2)));
	}
}
