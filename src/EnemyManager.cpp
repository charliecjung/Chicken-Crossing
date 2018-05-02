#include "Enemy.h"
#include "EnemyManager.h"
#include <vector>


std::vector <Enemy*> EnemyManager::createRandomEnemies(int numOfEnemies) {
	// testEnemy_ = new Enemy(200, 200, 200, 200, 20, 0);
	//std::vector <Enemy>* tempList = new std::vector <Enemy>();
	std::vector <Enemy*> tempList;

	for (unsigned int i = 0; i < numOfEnemies; i++) {

		// Cited from:
		// https://stackoverflow.com/questions/7887941/random-number-from-9-to-9-in-c
		//rand() negative generation -10 to 10
		int randomNumber = ((rand() % kRandGenEndMarker) - kRandGenStartMarker);
	
		if (randomNumber == 0) {
			int anotherRandom = rand() % 1;
			randomNumber = ((rand() % kRandGenEndMarker) - kRandGenStartMarker);
			if (anotherRandom == 1) {
				randomNumber = std::min(randomNumber, kRandMinMarker);
			}
			else if (anotherRandom == 0) {
				randomNumber = std::max(kRandMaxMarker, randomNumber);
			}
		}
		currentEnemy = new Enemy(((rand() % 1) + kRangeOfXSpawnLoc) * i, kRangeOfYSpawnLoc * i, kEnemyWidth, kEnemyHeight, randomNumber, kEnemySpeedMultiplier);
		int randomInt = ((rand() % kRandIntStart) + 1);
		int randomSecondInt = ((rand() % kRandIntEnd) + 1);
		//currentEnemy->setCurrentImage("images/enemies/Cars/Cars-01-" + ofToString(randomInt) + ofToString(randomSecondInt) + ".png");
		currentEnemy->getCurrentImage().load(carsPath_ + ofToString(randomInt) + ofToString(randomSecondInt) + imageExtension_);
		//tempList.push_back(*currentEnemy);
		tempList.push_back(currentEnemy);
		//delete currentEnemy;
		//currentEnemy = NULL;
	}
	return tempList;
}
void EnemyManager::SetUp() {
	enemyList_ = createRandomEnemies(enemyCount_);
}

// Iterating through a vector using a new iterator
// Cited from:
// https://stackoverflow.com/questions/12702561/iterate-through-a-c-vector-using-a-for-loop
void EnemyManager::draw() {
	for (std::vector<Enemy*> ::iterator it = enemyList_.begin(); it != enemyList_.end(); ++it)
	{
		auto temp = *it;

		(*it)->draw();
}	
}

bool EnemyManager::checkCollision(Player nextPlayer) {
	for (std::vector<Enemy*>::iterator it = enemyList_.begin(); it != enemyList_.end(); ++it)
	{
		bool isHit = (*it)->doOverlap(nextPlayer.getX(), nextPlayer.getY(), (nextPlayer.getX() + nextPlayer.getWidth()), (nextPlayer.getY() + nextPlayer.getHeight()), (*it)->getX(), (*it)->getY(), (*it)->getX() + (*it)->getWidth(), (*it)->getY() + (*it)->getHeight());
		if (isHit) {

			return true;
		}
	}
	return false;
}

std::vector <Enemy*> EnemyManager::getEnemyList() {
	return enemyList_;
}