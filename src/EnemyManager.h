#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H


#include "Player.h"
#include <vector>
#include "Enemy.h"
#include <string>
class EnemyManager {
public:
	void SetUp();
	void draw();
	bool checkCollision(Player nextPlayer);
	std::vector <Enemy*> getEnemyList();


private:
	std::vector <Enemy*> createRandomEnemies(int numOfEnemies);
	std::vector <Enemy*> enemyList_;
	Enemy* currentEnemy;
	const int kRandMinMarker = -20;
	const int kRandMaxMarker = 20;
	const int kRandGenStartMarker = -30;
	const int kRandGenEndMarker = 30;
	const int kRangeOfXSpawnLoc = 1000;
	const int kRangeOfYSpawnLoc = 350;
	const int kEnemyWidth = 200;
	const int kEnemyHeight = 150;
	const int kEnemySpeedMultiplier = 0;
	std::string carsPath_ = "images/enemies/Cars/Cars-01-";
	std::string imageExtension_ = ".png";
	int enemyCount_ = 6;
	const int kRandIntStart = 4;
	const int kRandIntEnd = 8;
	

};

























#endif //ENEMY_MANAGER_H
