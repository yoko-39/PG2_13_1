#pragma once
#include "Bullet.h"
class Enemy
{
public:
	static int EnemyAlive;
	Bullet* bullet_;
	Enemy(int posX, int posY, int radius, int speed, int alive);	
	void Move(char *keys, char *preKeys);
	void Draw();

public:

	int EnemyposX_;
	int EnemyposY_;
	int radius_;
	int speed_;
	int EnemyAlive_;
};

