#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "ofMain.h"
class Player {
	public:
		Player();
		ofImage getCurrentImage();
		int getX();
		int getY();
		int getWidth();
		int getHeight();
		int getSize();
		void setX(int newX);
		void setY(int newY);
		void setUp();
		const int getEndOfGameYLevel();
		bool isFrogStillAlive();
	private:

		ofImage currentImage;
		int x;
		int y;
		int width;
		int height;
		int size;
		const int endOfGameYLevel = 0;
		bool isAlive;


};

#endif //PLAYER_H