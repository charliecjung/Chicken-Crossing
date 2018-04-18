#include "Player.h"

Player::Player() {
	width = 100;
	height = 100;
	x = (ofGetWindowWidth() / 2) - width;
	y = ofGetWindowHeight() - height;
	isAlive = true;
	size = 50;
	
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


