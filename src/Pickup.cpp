#include "Pickup.h"

	Pickup::Pickup() {

	}
	int Pickup::getX() {
		return x_;
	}
	int Pickup::getY() {
		return y_;
	}
	int Pickup::getWidth() {
		return width_;
	}
	int Pickup::getHeight() {
		return height_;
	}
	bool Pickup::didCollide() {
		return ifCollided_;
	}
	ofImage Pickup::getCurrentImage() {
		return currentImage_;
	}
	Pickup::Pickup(int newX, int newY, int newWidth, int newHeight) {
		x_ = newX;
		y_ = newY;
		width_ = newWidth;
		height_ = newHeight;
	}
	void Pickup::draw() {
		currentImage_.draw(x_, y_, width_, height_);
	}
	void Pickup::setX(int newX) {
		x_ = newX;
	}
	void Pickup::setY(int newY) {
		y_ = newY;
	}
	void updatePosition(int speedCounter) {

	}
