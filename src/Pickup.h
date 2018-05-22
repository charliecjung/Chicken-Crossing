#ifndef PICKUP_H
#define PICKUP_H

#include "ofMain.h"

#include <string>
#include <vector>

class Pickup : public ofBaseApp {
public:
	Pickup();
	int getX();
	int getY();
	int getWidth();
	int getHeight();
	bool didCollide();
	ofImage getCurrentImage();
	Pickup(int newX, int newY, int newWidth, int newHeight);
	void draw();
	void setX(int newX);
	void setY(int newY);
	void setCurrentImage(std::string path);

private:

	int x_;
	int y_;
	int width_;
	int height_;
	bool ifCollided_;
	ofImage currentImage_;
};

#endif //PICKUP_H
