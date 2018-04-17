#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "ofMain.h"
class Player {
	public:

	private:
		ofImage currentImage;
		int x = (ofGetWindowWidth()/2)-width;
		int y = ofGetWindowHeight - height;
		int width = 50;
		int height = 50;
		int endOfGameYLevel = 0;
		bool isAlive = true;


};

#endif //PLAYER_H