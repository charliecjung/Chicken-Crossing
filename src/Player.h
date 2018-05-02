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
		int fixedWindowWidth_;
		int fixedWindowHeight_;
		int width_;
		int height_;
		int size_;

		int x_;
		int y_;

	ofImage chickenUp_;
	ofImage chickenLeft_;
	ofImage chickenRight_;
	ofImage chickenDown_;
	ofImage currentImage_;
    bool isAlive_;
};
#endif // PLAYER_H