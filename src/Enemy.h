#ifndef ENEMY_H
#define ENEMY_H

#include "ofMain.h"

#include <string>
#include <vector>
#include <string>

class Enemy: public ofBaseApp {
	public:
		Enemy();
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		bool didCollide();
		int getSpeed();
		ofImage& getCurrentImage();
		Enemy(int newX, int newY, int newWidth, int newHeight, int newSpeed, int newSpeedMultiplier);
		void draw();
		void setX(int newX);
		void setY(int newY);
		void setSpeed(int newSpeed);
		void updatePosition(int speedCounter);
		void setCurrentImage(std::string path);
		bool doOverlap(int leftX1, int leftY1, int rightX1, int rightY1, int leftX2, int leftY2, int rightX2, int rightY2);

	private:
		
		int x_;
		int y_;
		int width_;
		int height_;
		bool ifCollided_;
		int speed_;
		ofImage currentImage_;
		int speedMultiplier_;
		
};

#endif //ENEMY_H
