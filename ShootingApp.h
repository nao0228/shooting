#pragma once
#include "App.h"
#include "Fighter.h"
#include "EnemyA.h"
#include "Missile.h"
#include <vector>
#define N_ENEMY_A 2 // 敵機を2機
#define N_MISSILE 10 // ミサイルは10発


class ShootingApp :public App
{
private:
	Fighter fighter;
	Missile missile[N_MISSILE];
	EnemyA enemyA[N_ENEMY_A];
	void init();
	void cleanup();
	void update();
	void draw();
	void keyDown(WPARAM key);
	void keyUp(WPARAM key);
};

