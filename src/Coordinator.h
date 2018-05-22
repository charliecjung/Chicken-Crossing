#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "EnemyManager.h"
#include "PickupManager.h"
#include "Player.h"
#include "ofMain.h"
#include <vector>
#include "ofxCenteredTrueTypeFont.h"
#include <string>

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
	std::string robotoFont_ = "Roboto-Black.ttf";
	std::string backgroundImagePath_ = "images/images/backgroundImage.png";
	std::string soundPath_ = "music/backgroundMusic.flac";
	std::string gameOverText_ = "Game Over \n Press the SPACEBAR to start a new game.";
	std::string youWonText_ = "You Won!!! :D \n Press the SPACEBAR to start a new game.";
	std::string confusedInputText_ = "Cannot understand your next movement. Please try again.";
	const char kSurpriseKey = 'm';
	const int kSurpriseNumber = 900;
	//Using ofTruetypeFont

	ofxCenteredTrueTypeFont gameFont;

	

	
};

#endif // COORDINATOR_H