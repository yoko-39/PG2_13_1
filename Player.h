#pragma once
#include "Bullet.h"
class Player {
public:

	Bullet *bullet_;

	Player(int posX, int posY, int radius, int speed);
	~Player();
	void Move(char* keys);
	void Shot(char* keys, char *preKeys);
	void Draw();

public:
	int posX_;
	int posY_;
	int radius_;
	int speed_;
};