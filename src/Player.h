#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "ofmain.h"

class Player {
 public:

	ofImage getCurrentImage();
    int getX();
    int getY();
    int getWidth();
    int getHeight();
    int getSize();
    void setX(int newX);
    void setY(int newY);
	void draw();
	bool getAliveStatus();
	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	ofImage getChickenUp();
	ofImage getChickenLeft();
	ofImage getChickenDown();
	ofImage getChickenRight();
	void setAlive(bool lifeState);
	void loadBaseImages();

private:
	int fixedWindowWidth_ = Coordinator::Coordinator.gameWidth;
	int fixedWindowHeight_ = Coordinator::Coordinator.gameHeight;
	int width_ = 100;
	int height_ = 100;
	int isAlive_ = true;
	int size_ = 50;
	int x_ = fixedWindowWidth_;
	int y_ = fixedWindowHeight_;
	std::string chickenUpImagePath = "images/chicken/chicken_up.png";
	std::string chickenLeftImagePath = "images/chicken/chicken_left.png";
	std::string chickenRightImagePath = "images/chicken/chicken_right.png";
	std::string chickenDownImagePath = "images/chicken/chicken_down.png";
	ofImage chickenUp_;
	ofImage chickenLeft_;
	ofImage chickenRight_;
	ofImage chickenDown_;
	ofImage currentImage_;

};
#endif // PLAYER_H
