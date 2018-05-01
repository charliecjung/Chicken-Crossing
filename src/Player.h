#ifndef PLAYER_H
#define PLAYER_H

#include <string>

#include "ofMain.h"

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
    void setup();
    bool isFrogStillAlive();
	void draw();

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();
	ofImage getChickenUp();
	ofImage getChickenLeft();
	ofImage getChickenDown();
	ofImage getChickenRight();


    private:

    int x_;
    int y_;
    int width_;
    int height_;
    int size_;

	ofImage chickenUp_;
	ofImage chickenLeft_;
	ofImage chickenRight_;
	ofImage chickenDown_;
	ofImage currentImage_;
    bool isAlive_;
};
#endif // PLAYER_H