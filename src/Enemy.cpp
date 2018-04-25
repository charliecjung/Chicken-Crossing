
#include "Enemy.h"
#include <cstdlib>
#include <vector>
#include <string>

	Enemy::Enemy() {

	}

	Enemy::Enemy(int newX, int newY, int newWidth, int newHeight, int newSpeed, int newSpeedMultiplier) {
		x_ = newX;
		y_ = newY;
		width_ = newWidth;
		height_ = newHeight;
		ifCollided_ = false;
		speed_ = newSpeed;
		speedMultiplier_ = newSpeedMultiplier;
	}

	int Enemy::getX() {
		return x_;
	}
	
	int Enemy::getY() {
		return y_;
	}

	int Enemy::getWidth() {
		return width_;
	}

	int Enemy::getHeight() {
		return height_;
	}
	
	bool Enemy::didCollide() {
		return ifCollided_;
	}

	int Enemy::getSpeed() {
		return speed_;
	}
	ofImage Enemy::getCurrentImage() {
		return currentImage_;
	}
	void Enemy::setCurrentImage(std::string path) {
		currentImage_.load(path);
	}

	void Enemy::setX(int newX) {
		x_ = newX;
	}
	void Enemy::setY(int newY) {
		y_ = newY;
	}
	void Enemy::setSpeed(int newSpeed) {
		speed_ = newSpeed;
	}
	void Enemy::draw() {
		updatePosition(speedMultiplier_);
		currentImage_.draw(x_, y_, width_, height_);
		
	}
	
	void Enemy::updatePosition(int speedCounter) {
		speed_ += speedCounter;
		if (x_ >= ofGetWindowWidth()) {
			// then the car is out of the screen
			x_ = 0;
		}
		else if (x_ <= (0 - (width_ * 2))) {
			x_ = ofGetWindowWidth();
		}
			x_ = x_ + speed_;
	}
	