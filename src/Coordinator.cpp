#include "Player.h"
#include "Coordinator.h"
#include "Enemy.h"
#include "ofMain.h"
#include "ofxGui.h"
#include <vector>
//--------------------------------------------------------------


// This is Coordinator loading all of the game sprites and sound files.

void Coordinator::setup() {
	
	backgroundImage_.load("images/images/backgroundImage.png");

	SoundPlayer_.load("music/backgroundMusic.flac");
	
	
	eManager.SetUp();
	/*
	powerup1 = new Pickup(200, 200, 200, 200);
	powerup1->setCurrentImage("images/powerups/potionBlue.png");
	*/
	player_.loadBaseImages();
	player_.setup();

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
	// std::cout << "FPS: " + ofToString(ofGetFrameRate()) << std::endl;
	// doOverlap(player_.getX(), player_.getY(), (player_.getX() + player_.getWidth()), (player_.getY() + player_.getHeight()), testEnemy_->getX(), testEnemy_->getY(), (testEnemy_->getX() + testEnemy_->getWidth()), (testEnemy_->getY() + testEnemy_->getHeight()));

	glPolygonMode(GL_BACK, GL_FILL);
	backgroundImage_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	glPolygonMode(GL_FRONT, GL_FILL);

	player_.draw();
	/*
	powerup1->draw();
	*/
	eManager.draw();
		
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
		/*
		delete powerup1;
		powerup1 = NULL;
		delete currentEnemy;
		currentEnemy = NULL;
		delete enemyList_;
		enemyList_ = NULL;
		*/
		isGameOver = true;
	}
	
	else {
		std::cout << "Cannot understand your next movement. Please try again." << std::endl;
	}
}


	void Coordinator::KillPlayer() {
		isGameOver = eManager.checkCollision(player_);

		if (player_.getY() <= 0) {
			ofSetColor(255, 255, 0);
			glPolygonMode(GL_FRONT, GL_FILL);
			isGameOver = true;
		}
		if (isGameOver) {
			GameOver();
		}
	}
	void Coordinator::GameOver() {
		// std::cout << "Game Over" << std::endl;
		//Just freeze everything; don't std::exit();
		SoundPlayer_.stop();
		player_.setAlive(false);

		
		

	}
	void Coordinator::ResetGame() {
		isGameOver = false;

	}

