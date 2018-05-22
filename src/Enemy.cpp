
#include "Enemy.h"
#include <cstdlib>
#include <vector>
#include <string>
#include "Coordinator.h"

	Enemy::Enemy() {

	}

	Enemy::Enemy(int newX, int newY, int newWidth, int newHeight, int newSpeed, int newSpeedMultiplier) {
		x_ = newX;
		y_ = newY;
		width_ = newWidth;
		height_ = newHeight;
		isCollided_ = false;
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
		return isCollided_;
	}

	int Enemy::getSpeed() {
		return speed_;
	}
	ofImage& Enemy::getCurrentImage() {
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
		
		if (Coordinator::kIsGameOver == false) {
			updatePosition(0);
		} 
		currentImage_.draw(x_, y_, width_, height_);
	}
	
	void Enemy::updatePosition(int speedCounter) {
		if (isCollided_) {
			speed_ = 0;
		}
		else {

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
	}
	
	//
	// Referenced from:
	// https://www.geeksforgeeks.org/find-two-rectangles-overlap/

	// l1: Top Left coordinate of first rectangle.
	// r1: Bottom Right coordinate of first rectangle.
	// l2 : Top Left coordinate of second rectangle.
	// r2 : Bottom Right coordinate of second rectangle.


	// Cited for intersection of two rectangle's logic:
	// https://www.geeksforgeeks.org/find-two-rectangles-overlap/
	bool Enemy::doOverlap(int leftX1, int leftY1, int rightX1, int rightY1, int leftX2, int leftY2, int rightX2, int rightY2) {
		if ((leftX1 > rightX2 || leftX2 > rightX1) || (leftY1 > rightY2 || leftY2 > rightY1)) {
			glPolygonMode(GL_FRONT, GL_FILL);
			return false;
		}
		
		glPolygonMode(GL_FRONT, GL_FILL);
		isCollided_ = true;
		return true;
	}

	