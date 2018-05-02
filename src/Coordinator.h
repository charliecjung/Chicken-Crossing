#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "EnemyManager.h"
#include "PickupManager.h"
#include "Player.h"
#include "ofMain.h"
#include <vector>
#include "ofxCenteredTrueTypeFont.h"

class Coordinator : public ofBaseApp {
	public:
	bool static kIsGameOver;
	bool static kResetGame;
	void setup();
	void update();
	void draw();
	void keyPressed(int key);
	void KillPlayer();
	void GameOver();
	void ResetGame();
	


	//
	// Referenced from:
	// https://www.geeksforgeeks.org/find-two-rectangles-overlap/

	// l1: Top Left coordinate of first rectangle.
	// r1: Bottom Right coordinate of first rectangle.
	// l2 : Top Left coordinate of second rectangle.
	// r2 : Bottom Right coordinate of second rectangle.
	
	private:

	Player player_;
	ofSoundPlayer SoundPlayer_;
	ofImage backgroundImage_;
	PickupManager pManager;
	EnemyManager eManager;
	const int kGameFontSize = 100;
	//Using ofTruetypeFont

	ofxCenteredTrueTypeFont gameFont;

	
};

#endif // COORDINATOR_H