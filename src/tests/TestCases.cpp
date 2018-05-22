#define CATCH_CONFIG_RUNNER
#include "catch.hpp"

// Checking the currentImage's possible images:
//  chickenUp, chickenLeft, chickenRight, chickenDown

/*

TEST_CASE( "check chickenUp Image") {
	REQUIRE(player_.chickenUpImagePath == "images/chicken/chicken_up.png");
	
}
TEST_CASE("check chickenLeft Image") {
	REQUIRE(player_.chickenLeftImagePath == "images/chicken/chicken_left.png");
}
TEST_CASE("check chickenRight Image") {
	REQUIRE(player_.chickenRightImagePath == "images/chicken/chicken_right.png");
}
TEST_CASE("check chickenDown Image") {
	REQUIRE(player_.chickenDownImagePath == "images/chicken/chicken_down.png");
}

TEST_CASE("check if currentImage_ it not null ") {
	REQUIRE(player_.currentImage_ == chickenUp_);
}


// Checking Player Properties

TEST_CASE("Check the width of the Player") {
	REQUIRE(player_.getWidth() == 100);
}

TEST_CASE("Check the height of the Player") {
	REQUIRE(player_.getHeight() == 100);
}

TEST_CASE("Check the size of the player") {
	REQUIRE(player_.getSize() == 50);
}


TEST_CASE("Checking the MoveLeft() function") {
	//Set player's x to some arbitrary x
	player_.setX(300);
	player_.setY(300);
	player_.MoveLeft();
	player_.MoveLeft();
	REQUIRE(player_.getX() == (300 - (player.getSize() * 2)));
}

TEST_CASE("Checking the MoveRight() function") {
	//Set player's x to some arbitrary x
	player_.setX(400);
	player_.setY(400);
	player_.MoveRight();
	player_.MoveRight();
	player_.MoveRight();
	player_.MoveRight();
	player_.MoveRight();
	REQUIRE(player_.getX() == (400 + (player.getSize() * 5)));
}

TEST_CASE("Checking the MoveUp() function") {
	//set Player's y to some arbitrary y
	player_.setX(200);
	player_.setY(800);
	player_.MoveUp();
	player_.MoveUp();
	player_.MoveUp();
	REQUIRE(player_.getY() == (800 - (player_.getSize() * 3)));
}

TEST_CASE("Checking the MoveDown() function") {
	player_.setX(500);
	player_.setY(500);
	player_.MoveDown();
	player_.MoveDown();
	player_.MoveDown();
	player_.MoveDown();
	player_.MoveDown();
	REQUIRE(player_.getY() == (500 + (player.getSize() * 5);
}

// Checking Enemy Manager Functions

TEST_CASE("Checking Enemy Manager createEnemies()") {
	std::vector <Enemy*> eList;
	EnemyManager eM;
	eList = eM.createRandomEnemies(10);
	REQUIRE(eM.getEnemyList().size() == 10);
}

TEST_CASE("Checking kRandMinMarker value") {
	EnemyManager eM;
	REQUIRE(eM.kRandMinMarker == -10);
}
TEST_CASE("Checking kRandMaxMarker value") {
	EnemyManager eM;
	REQUIRE(eM.kRandMaxMarker == 10);
}

TEST_CASE("Checking kRandGenStartMarker value") {
	EnemyManager eM;
	REQUIRE(eM.kRandGenStartMarker == -15);
}

TEST_CASE("Checking kRandGenEndMarker value") {
	EnemyManager eM;
	REQUIRE(eM.kRandGendEndMarker == 31);
}

TEST_CASE("Checking kRangeOfXSpawnLoc value") {
	EnemyManager eM;
	REQUIRE(eM.kRangeOfXSpawnLoc == 1000);


}

TEST_CASE("Checking kRangeOfYSpawnLoc value") {
	EnemyManager eM;
	REQUIRE(eM.kRangeOfYSpawnLoc == 350);
}

TEST_CASE("Checking enemyList is not null") {
	EnemyManager eM;
	REQUIRE(eM.getEnemyList().size() > 0);
}

// Check Enemy's Overlap function:

TEST_CASE("Check if two rectangles are inside each other: ") {
	// Verdict should be true
	Enemy firstEnemy;
	Enemy secondEnemy;


	firstEnemy.leftX1 = 0;
	firstEnemy.leftY1 = 0;
	firstEnemy.rightX1 = 50;
	firstEnemy.rightY1 = 0;
	firstEnemy.leftX2 = 0;
	firstEnemy.leftY2 = 50;
	firstEnemy.rightX2 = 50;
	firstEnemy.rightY2 = 50;

	secondEnemy.leftX1 = 25;
	secondEnemy.leftY1 = 25;
	secondEnemy.rightX1 = 75;
	secondEnemy.rightY1 = 25;
	secondEnemy.leftX2 = 25;
	secondEnemy.leftY2 = 75;
	secondEnemy.rightX2 = 75;
	secondEnemy.rightY2 = 75;

	//setup is all done

	bool result = firstEnemy.doOverlap(secondEnemy.leftX1, secondEnemy.leftY1, secondEnemy.rightX1, secondEnemy.rightY1, secondEnemy.leftX2, secondEnemy.leftY2, secondEnemy.rightX2, secondEnemy.rightY2);
	REQUIRE(result == true);
}

TEST_CASE("Check if two rectangles are inside each other: ") {
	// Verdict should be false
	Enemy firstEnemy;
	Enemy secondEnemy;


	firstEnemy.leftX1 = 0;
	firstEnemy.leftY1 = 0;
	firstEnemy.rightX1 = 50;
	firstEnemy.rightY1 = 0;
	firstEnemy.leftX2 = 0;
	firstEnemy.leftY2 = 350;
	firstEnemy.rightX2 = 50;
	firstEnemy.rightY2 = 350;

	secondEnemy.leftX1 = 100;
	secondEnemy.leftY1 = 200;
	secondEnemy.rightX1 = 200;
	secondEnemy.rightY1 = 200;
	secondEnemy.leftX2 = 100;
	secondEnemy.leftY2 = 500;
	secondEnemy.rightX2 = 200;
	secondEnemy.rightY2 = 500;
	bool result = firstEnemy.doOverlap(secondEnemy.leftX1, secondEnemy.leftY1, secondEnemy.rightX1, secondEnemy.rightY1, secondEnemy.leftX2, secondEnemy.leftY2, secondEnemy.rightX2, secondEnemy.rightY2);
	REQUIRE(result == true);
	//result should be false as these two rectangles are not overlapping.



}

//bool doOverlap(int leftX1, int leftY1, int rightX1, int rightY1, int leftX2, int leftY2, int rightX2, int rightY2);

//Check if kIsGameOver, then all cars should be frozen.

TEST_CASE("Check if cars are frozen when bird is hit") {
	std::vector <int> speeds;
	std::vector <int> arrayFullOfZeroes;
	for (int j = 0; j < enemyManager.getEnemyList().size(); j++) {
		arrayFullOfZeros.push_back(0);
	}
	if (Coordinator::kisGameOver) {
		for (int i = 0; i < enemyManager.getEnemyList().size(); i++) {
			speeds.push_back(enemyManager.getEnemyList()[i].getSpeed());
		}
	}
	COMPARE_ARRAYS(speeds, arrayFullOfZeroes);

}

TEST_CASE("Check car's speed when the 'm' key is pushed.") {
	std::vector <int> speeds;
	std::vector <int> arrayFullOfNineHundreds;
	for (int j = 0; j < enemyManager.getEnemyList().size(); j++) {
		arrayFullOfNineHundreds.push_back(900);
	}
	if (Coordinator::kisGameOver) {
		for (int i = 0; i < enemyManager.getEnemyList().size(); i++) {
			speeds.push_back(enemyManager.getEnemyList()[i].getSpeed());
		}
	}
	COMPARE_ARRAYS(speeds, arrayFullOfNineHundreds);

}

TEST_CASE("Check roboto font") {
	Coordinator coordinator;
	REQUIRE(coordinator.robotoFont == "Roboto-Black.ttf");
}

TEST_CASE("Check backgroundImagePath_") {
	Coordinator coordinator;
	REQUIRE(coordinator.backgroundImagePath_ == "images/images/backgroundImage.png");

}

TEST_CASE("Check soundPath_") {
	Coordinator coordinator;
	REQUIRE(coordinator.soundPath_ == "music/backgroundMusic.flac");
}

TEST_CASE("Check gameOverText_") {
	Coordinator coordinator;
	REQUIRE(coordinator.gameOverText_ == "Game Over \n Press the SPACEBAR to start a new game.");
}

TEST_CASE("Check youWonText_") {
	Coordinator coordinator;
	REQUIRE(coordinator.youWonText_ == "You won!!! :D \n Press the SPACEBAR to start a new game.");
}

TEST_CASE("Check confusedInputText_") {
	Coordinator coordinator;
	REQUIRE(coordinator.confusedInputText_ == "Cannot understand your next momvement. Please try again.");
}

TEST_CASE("Check if gameFont is null") {
	Coordinator coordinator;
	REQUIRE(coordinator.gameFont != null);
}

*/