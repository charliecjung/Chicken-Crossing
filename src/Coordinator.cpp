#include "Player.h"
#include "Coordinator.h"
#include "Enemy.h"
#include "ofMain.h"
#include "ofxGui.h"
#include <vector>
//--------------------------------------------------------------


// This is Coordinator loading all of the game sprites and sound files.
bool Coordinator::kIsGameOver = false;
bool Coordinator::kResetGame = false;
void Coordinator::setup() {
	ofSoundStopAll();
	ofSoundStreamClose();
	gameFont.load(robotoFont_, kGameFontSize);

	backgroundImage_.load(backgroundImagePath_);
	if (SoundPlayer_.isLoaded() == false) {
		SoundPlayer_.load(soundPath_);
	}

	eManager.SetUp();
	player_.loadBaseImages();
	if (SoundPlayer_.isPlaying() == false) {
	SoundPlayer_.setLoop(true);
	SoundPlayer_.play();
}

}


// RM's update() method. Obsolete as draw() seems to be superior at this point.

//--------------------------------------------------------------
void Coordinator::update() {
	KillPlayer();
	if (kIsGameOver) {

	}

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

	if (kIsGameOver && player_.getY() > 0 ){

		//gameFont.drawStringCentered("Game Over \n Press the SPACEBAR to start a new game.", (ofGetWindowWidth() / 2) - (gameFont.stringWidth("				Game Over \n Press the SPACEBAR to start a new game.") / 2), (ofGetWindowHeight() / 2) - (gameFont.stringHeight("Game Over \n Press the SPACEBAR to start a new game.") / 2));
		
		gameFont.drawStringCentered(gameOverText_, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	}
	else if (kIsGameOver && player_.getY() <= 0) {
		gameFont.drawStringCentered(youWonText_, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
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
	else if (key == ' ') {
		if (Coordinator::kIsGameOver == true && Coordinator::kResetGame == false) {
			ResetGame();
		}

	}
	else if (key == OF_KEY_ESC) {
		ofToggleFullscreen();
	}
	else if (key == OF_KEY_RETURN) {
		for (int i = 0; i < eManager.getEnemyList().size(); i++) {
			delete eManager.getEnemyList()[i];
		}
		std::exit(0);
	}
	else if (key == kSurpriseKey) {
		for (int i = 0; i < eManager.getEnemyList().size();  i++) {
			eManager.getEnemyList()[i]->updatePosition(kSurpriseNumber);
		}
	}
	else {
		std::cout << confusedInputText_ << std::endl;
	}
}


void Coordinator::KillPlayer() {
	kIsGameOver = eManager.checkCollision(player_);

	if (player_.getY() <= 0) {
		glPolygonMode(GL_FRONT, GL_FILL);
		kIsGameOver = true;
		
	}
	if (kIsGameOver) {
		
		GameOver();

	}
}
void Coordinator::GameOver() {
	// std::cout << "Game Over" << std::endl;
	//Just freeze everything; don't std::exit();
	SoundPlayer_.setLoop(false);
	SoundPlayer_.stop();
	player_.setAlive(false);
	
}

void Coordinator::ResetGame() {

	kResetGame = false;
	kIsGameOver = false;
	ofRunApp(new Coordinator());

}

