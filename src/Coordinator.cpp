#include "Player.h"
#include "Coordinator.h"
#include "Enemy.h"
#include "ofMain.h"
#include "ofxGui.h"
#include <vector>

bool Coordinator::kIsGameOver = false;
bool Coordinator::kResetGame = false;
void Coordinator::setup() {
	//stop sounds

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
	glPolygonMode(GL_BACK, GL_FILL);
	backgroundImage_.draw(0, 0, ofGetWindowWidth(), ofGetWindowHeight());
	glPolygonMode(GL_FRONT, GL_FILL);

	player_.draw();
	eManager.draw();

	if (kIsGameOver && player_.getY() > 0 ){	
		gameFont.drawStringCentered(gameOverText_, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	}
	else if (kIsGameOver && player_.getY() <= 0) {
		gameFont.drawStringCentered(youWonText_, ofGetWindowWidth() / 2, ofGetWindowHeight() / 2);
	}

}

//--------------------------------------------------------------

// Citing from:
// https://forum.openframeworks.cc/t/call-keypressed-in-draw-function/12880/2

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

