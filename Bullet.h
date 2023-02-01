#pragma once
class Bullet
 {
public:
	Bullet(int posX, int posY, int radius, int speed, int isShot);
	
	void Move();
	void Draw();

public:
	  
		int BulletposX_;
		int BulletposY_;
		int radius_;
		int speed_;
		int isShot_;
	
};
