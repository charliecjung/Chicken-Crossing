#include "Player.h"

#include "ofxGui.h"


Player::Player() {
	width_ = 100;
	height_ = 100;
	isAlive_ = true;
	size_ = 50;
	x_ = (ofGetWindowWidth() / 2) - (size_ * 2);
	y_ = (ofGetWindowHeight() - (size_ * 2));
}

// Player's setup method where I fill in the variables for a Player object (on the stack).

void Player::setUp() {

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


