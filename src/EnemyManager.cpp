#include "Enemy.h"
#include "EnemyManager.h"
#include <vector>


std::vector <Enemy*> EnemyManager::createRandomEnemies(int numOfEnemies) {
	// testEnemy_ = new Enemy(200, 200, 200, 200, 20, 0);
	std::vector <Enemy>* tempList = new std::vector <Enemy>();

	for (unsigned int i = 0; i < numOfEnemies; i++) {
		// Cited from:
		// https://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c
		//rand() negative generation -10 to 10
		int randomNumber = ((rand() % 60) - 30);
		if (randomNumber == 0) {
			int anotherRandom = rand() % 1;
			randomNumber = ((rand() % 60) - 30);
			if (anotherRandom == 1) {
				randomNumber = std::min(randomNumber, -11);
			}
			else if (anotherRandom == 0) {
				randomNumber = std::max(11, randomNumber);
			}
		}
		currentEnemy = new Enemy(((rand() % 1) + 1000) * i, 350 * i, 200, 150, randomNumber, 0);
		int randomInt = (rand() % 4);
		int randomSecondInt = (rand() % 8);
		//currentEnemy->setCurrentImage("images/enemies/Cars/Cars-01-" + ofToString(randomInt) + ofToString(randomSecondInt) + ".png");
		currentEnemy->getCurrentImage().load("images/enemies/Cars/Cars-01-" + ofToString(randomInt) + ofToString(randomSecondInt) + ".png");
		//tempList.push_back(*currentEnemy);
		tempList->push_back(*currentEnemy);
		//delete currentEnemy;
		//currentEnemy = NULL;
	}
	return tempList;
}
void EnemyManager::SetUp() {
	enemyList_ = createRandomEnemies(5);
}

// Iterating through a vector using a new iterator
// Cited from:
// https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop
void EnemyManager::draw() {
for (std::vector<Enemy>::iterator it = enemyList_.begin(); it != enemyList_.end(); ++it)
{
	it->draw();
}
}

void EnemyManager::checkCollision(Player nextPlayer) {
	for (std::vector<Enemy>::iterator it = enemyList_.begin(); it != enemyList_.end(); ++it)
	{
		it->doOverlap(nextPlayer.getX(), nextPlayer.getY(), (nextPlayer.getX() + nextPlayer.getWidth()), (nextPlayer.getY() + nextPlayer.getHeight()), it->getX(), it->getY(), (it->getX() + it->getWidth()), (it->getY() + it->getHeight()));
	}
}