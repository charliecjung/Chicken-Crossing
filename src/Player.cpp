#include "Player.h"
#include "ofxGui.h"


Player::Player() {
	width = 100;
	height = 100;

	isAlive = true;
	size = 50;
	x = (ofGetWindowWidth() / 2) - (size * 2);
	y = (ofGetWindowHeight() - (size * 2));
}

void Player::setUp() {
	//Acts as a @Before
	width = 100;
	height = 100;
	isAlive = true;
	size = 50;
	//Hardcoded Constants for bottom middle of screen. (Screen dimensions not created yet)
	x = 1820;
	y = 2060;
	//x = (ofGetWindowWidth() / 2) - (size * 2);
	//y = (ofGetWindowHeight() - (size * 2));
}
ofImage Player::getCurrentImage() {
	return currentImage;
}

int Player::getX() {
	return x;
}
int Player:: getY() {
	return y;
}
int Player::getWidth() {
	return width;
}
int Player::getSize() {
	return size;
}
int Player::getHeight() {
	return height;
}
const int Player::getEndOfGameYLevel() {
	return endOfGameYLevel;
}
void Player::setX(int newX) {
	x = newX;
}
void Player::setY(int newY) {
	y = newY;
}
bool Player::isFrogStillAlive() {
	return isAlive;
}


