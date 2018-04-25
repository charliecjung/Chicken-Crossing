#include "Player.h"
#include "ofxGui.h"

#include <string>



// Player's setup method where I fill in the variables for a Player object (on the stack).

void Player::setup() {

	// Acts as a @Before (In Catch cases).

	width_ = 100;
	height_ = 100;
	isAlive_ = true;
	size_ = 50;

	// Hardcoded Constants for bottom middle of screen. Used to place the frog in the beginning position of the game
    // Starts the frog off on the other side of the road (bottom side).

	x_ = 1820;
	y_ = 2060;

	// x = (ofGetWindowWidth() / 2) - (size * 2);
	// y = (ofGetWindowHeight() - (size * 2));


	chickenUp_.load("images/chicken/chicken_up.png");
	chickenLeft_.load("images/chicken/chicken_left.png");
	chickenRight_.load("images/chicken/chicken_right.png");
	chickenDown_.load("images/chicken/chicken_down.png");
	currentImage_.load("images/chicken/chicken_up.png");
}
ofImage Player::getCurrentImage() {
	return currentImage_;
}

int Player::getX() {
	return x_;
}
int Player:: getY() {
	return y_;
}
int Player::getWidth() {
	return width_;
}
int Player::getSize() {
	return size_;
}
int Player::getHeight() {
	return height_;
}
const int Player::getEndOfGameYLevel() {
	return kEndOfGameYLevel_;
}
void Player::setX(int newX) {
	x_ = newX;
}
void Player::setY(int newY) {
	y_ = newY;
}
bool Player::isFrogStillAlive() {
	return isAlive_;
}

void Player::draw() {
	glPolygonMode(GL_FRONT, GL_FILL);
	currentImage_.draw(x_, y_, width_, height_);
	if (y_ <= 0) {
		std::exit(0);
	}
}



//To Preface This:
// I did some game-testing because I suspected that the ofGetWindowWidth() and ofGetWindowHeight() were actually bigger than 
// the screen by a small number of pixels (<~10)... so I was able to display the values of screenWidth and screenHeight using
// ofDrawLine() and was able to make calculations based off of feel.

// Another note is that I chose Coordinator to handle the implementation for move and then hand it off to Player when a key is
// pressed. 

// This is because I wanted to "sanitize" or check the input of the Player so they aren't changing their x/y position by like
// 1000 pixels or able to escape the boundaries by modifying my edge cases.

//This way player movement is consistent through all the Player objects

void Player::MoveLeft() {

	// Case for left edge of screen

	// update sprite's image
	currentImage_ = chickenLeft_;

	// futureXPos is x coord + body of sprite.
	
	int futureXPos = x_ - size_;

	//x_ = std::max(0, futureXPos);
	
	if (x_ > 0) {

		// if the future position is to the right of the left boundary, then update position

		x_ = futureXPos;
		

	}
	else if (futureXPos <= 0) {

		// if we are going out of the screen then trap the player to the left most position.

		x_ = 0;
	}
	
}
void Player::MoveRight() {

	// Case for right edge of screen

	//update sprite image

	currentImage_ = chickenRight_;

	//updated futureXPos

	int futureXPos = x_ + size_;

	if (futureXPos < (ofGetWindowWidth() - (size_ * 2))) {
		// This was a tricky edge case where I realized that for the player + body of sprite to touch the boundary of the 
		// visible screen was actually screenWidth - 100. Therefore, I got the screenWidth - (2*sizeofSprite): sizeOfSprite = 50;

		x_ = futureXPos;
	}
	else if (futureXPos >= (ofGetWindowWidth() - (size_ * 2))) {

		// This logic is if the player is beyond the boundary then trap the player within the screen.

		x_ = (ofGetWindowWidth() - (size_ * 2));
	}

}
void Player::MoveUp() {

	// Case for top edge of screen

	// update Sprite position

	currentImage_ = chickenUp_;

	//update futureYPos

	int futureYPos = y_ - size_;

	// if the sprite is below the top edge of the screen

	if (futureYPos > 0) {

		y_ = futureYPos;
	
	}
	// if the sprite is beyond the screen, trap it within!

	else if (futureYPos <= 0) {
		y_ = 0;
	}

}
void Player::MoveDown() {
	currentImage_ = chickenDown_;

	// Case for bottom edge of screen

	//update futureYPos

	int futureYPos = y_ + size_;

	// This was a tricky edge case where I realized that for the player + body of sprite to touch the boundary of the 
	// visible screen was actually screenWidth - 100. Therefore, I got the screenWidth - (2*sizeofSprite): sizeOfSprite = 50;

	if (futureYPos < (ofGetWindowHeight() - (size_ * 2))) {
		y_ = futureYPos;
	}

	//Same logic applies down below.

	else if (futureYPos >= (ofGetWindowHeight() - (size_ * 2))) {
		y_ = (ofGetWindowHeight() - (size_ * 2));
	}
}

ofImage Player::getChickenUp() {
	return chickenUp_;
}
ofImage Player::getChickenLeft() {
	return chickenLeft_;
}
ofImage Player::getChickenDown() {
	return chickenDown_;
}
ofImage Player::getChickenRight() {
	return chickenRight_;
}


