#include "Player.h"
#include "Coordinator.h"
#include "Enemy.h"
#include "ofMain.h"
#include "ofxGui.h"
#include <vector>
//--------------------------------------------------------------


// This is Coordinator loading all of the game sprites and sound files.

void Coordinator::setup() {
	player_.setup();
	
	backgroundImage_.load("images/images/backgroundImage.png");

	SoundPlayer_.load("music/backgroundMusic.flac");

	// (int newX, int newY, int newWidth, int newHeight, int newSpeed, int newSpeedMultiplier);

	//testEnemy_ = new Enemy(200, 200, 200, 200, 20, 0);
	
	enemyList_ = createRandomEnemies(5);


	powerup1 = new Pickup(200, 200, 200, 200);
	powerup1->setCurrentImage("images/powerups/potionBlue.png");

	SoundPlayer_.setLoop(true);
	SoundPlayer_.play();

}

// RM's update() method. Obsolete as draw() seems to be superior at this point.

//--------------------------------------------------------------
void Coordinator::update() {
	KillPlayer();
	
	
}
// Cited from:
// https://forum.openframeworks.cc/t/background-image-in-openframeworks-app/11731

// draw() is helpful for drawing sprites on the screen in a timely fashion.
// I am using the default settings that are provided for now and will see if I can
// fine tune it to adjust gameplay.

//--------------------------------------------------------------
void Coordinator::draw() {
	std::cout << "FPS: " + ofToString(ofGetFrameRate()) << std::endl;
	//doOverlap(player_.getX(), player_.getY(), (player_.getX() + player_.getWidth()), (player_.getY() + player_.getHeight()), testEnemy_->getX(), testEnemy_->getY(), (testEnemy_->getX() + testEnemy_->getWidth()), (testEnemy_->getY() + testEnemy_->getHeight()));

	glPolygonMode(GL_BACK, GL_FILL);
	backgroundImage_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	glPolygonMode(GL_FRONT, GL_FILL);
	/*
	ofDrawBitmapString("Player X: " + ofToStri`ng(player_.getX()), 400, 600);
	ofDrawBitmapString("Player Y: " + ofToString(player_.getY()), 800, 600);
	ofDrawBitmapString("testEnemy X: " + ofToString(testEnemy_->getX()), 400, 800);
	ofDrawBitmapString("testEnemy Y: " + ofToString(testEnemy_->getY()), 800, 800);
	*/

	player_.draw();
	powerup1->draw();
	// Iterating through a vector using a new iterator
	// Cited from:
	// https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop
	
	for (std::vector<Enemy>::iterator it = enemyList_->begin(); it != enemyList_->end(); ++it)
		{
			it->draw();
		}
		
}


//--------------------------------------------------------------

// Citing from:
// https://forum.openframeworks.cc/t/call-keypressed-in-draw-function/12880/2

// This handles the key presses of the arrow keys for the movement of the frog.

void Coordinator::keyPressed(int key) {
	if (key == OF_KEY_UP) {
		player_.MoveUp();
	}
	else if (key == OF_KEY_LEFT) {
		player_.MoveLeft();
	}
	else if (key == OF_KEY_RIGHT) {
		player_.MoveRight();
	}
	else if (key == OF_KEY_DOWN) {
		player_.MoveDown();
	}
	else if (key == 'p') {
		ofToggleFullscreen();

	}
	
	else if (key == OF_KEY_ESC) {
		delete powerup1;
		powerup1 = NULL;
		delete currentEnemy;
		currentEnemy = NULL;
		delete enemyList_;
		enemyList_ = NULL;
		isGameOver = true;
	}
	
	else {
		std::cout << "Cannot understand your next movement. Please try again." << std::endl;
	}
}


	void Coordinator::KillPlayer() {
		for (std::vector<Enemy>::iterator it = enemyList_->begin(); it != enemyList_->end(); ++it)
		{
			doOverlap(player_.getX(), player_.getY(), (player_.getX() + player_.getWidth()), (player_.getY() + player_.getHeight()), it->getX(), it->getY(), (it->getX() + it->getWidth()), (it->getY() + it->getHeight()));
		}

		if (player_.getY() <= 0) {
			ofSetColor(255, 255, 0);
			glPolygonMode(GL_FRONT, GL_FILL);
			isGameOver = true;
		}
	}
	void Coordinator::GameOver() {
		if (isGameOver) {
			std::cout << "Game Over" << std::endl;
			//Just freeze everything; don't std::exit();
		}

	}
	void Coordinator::ResetGame() {
		isGameOver = false;

	}

