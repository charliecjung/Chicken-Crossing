#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H


#include "Player.h"
#include <vector>
#include "Enemy.h"
class EnemyManager {
public:
	void SetUp();
	void draw();
	void checkCollision(Player nextPlayer);

private:
	std::vector <Enemy*> createRandomEnemies(int numOfEnemies);
	std::vector <Enemy*> enemyList_ = new std::vector <Enemy>();
	Enemy* currentEnemy;

};

























#endif //ENEMY_MANAGER_H
