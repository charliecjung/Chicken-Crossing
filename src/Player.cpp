#include "Player.h"
#include "ofxGui.h"

#include <string>



// Player's setup method where I fill in the variables for a Player object (on the stack).
void Player::setup() {

	// Hardcoded Constants for bottom middle of screen. Used to place the chicken in the beginning position of the game
	// Starts the chicken off on the other side of the road (bottom side).
	fixedWindowWidth_ = 1820;
	fixedWindowHeight_ = 2060;

	width_ = 100;
	height_ = 100;
	isAlive_ = true;
	size_ = 50;

	x_ = fixedWindowWidth_;
	y_ = fixedWindowHeight_;
	

}


ofImage Player::getCurrentImage() {
	return currentImage_;
}

void Player::loadBaseImages() {
	chickenUp_.load("images/chicken/chicken_up.png");
	chickenLeft_.load("images/chicken/chicken_left.png");
	chickenRight_.load("images/chicken/chicken_right.png");
	chickenDown_.load("images/chicken/chicken_down.png");
	currentImage_.load("images/chicken/chicken_up.png");
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
void Player::setX(int newX) {
	if (isAlive_) {
		x_ = newX;
	}
}
void Player::setY(int newY) {
	if (isAlive_) {
		y_ = newY;
	}
}
void Player::draw() {
	glPolygonMode(GL_FRONT, GL_FILL);
	currentImage_.draw(x_, y_, width_, height_);
	
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
	if (isAlive_) {
		currentImage_ = chickenLeft_;

		// futureXPos is x coord + body of sprite.

		int futureXPos = x_ - size_;

		x_ = std::max(0, futureXPos);

		if (x_ == 0) {
			x_ = ofGetWindowWidth() - (size_ * 2);
		}
	}
}

void Player::MoveRight() {
	if (isAlive_) {
		currentImage_ = chickenRight_;

		//updated futureXPos

		int futureXPos = x_ + size_;

		x_ = std::min(futureXPos, (ofGetWindowWidth() - (size_ * 2)));

		if (x_ == (ofGetWindowWidth() - (size_ * 2))) {
			x_ = 0 - (size_ * 2);
		}
	}
}
void Player::MoveUp() {
	if (isAlive_) {
		currentImage_ = chickenUp_;

		int futureYPos = y_ - size_;
		y_ = std::max(futureYPos, 0);
	}
}
void Player::MoveDown() {
	if (isAlive_) {
		currentImage_ = chickenDown_;

		int futureYPos = y_ + size_;

		// This was a tricky edge case where I realized that for the player + body of sprite to touch the boundary of the 
		// visible screen was actually screenWidth - 100. Therefore, I got the screenWidth - (2*sizeofSprite): sizeOfSprite = 50;

		y_ = std::min(futureYPos, (ofGetWindowHeight() - (size_ * 2)));
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

void Player::setAlive(bool lifeState) {
	isAlive_ = lifeState;
}

bool Player::getAliveStatus() {
	return isAlive_;
}



