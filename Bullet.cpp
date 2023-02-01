#include <Novice.h>
#include "Bullet.h"

Bullet::Bullet(int posX, int posY, int radius, int speed, int isShot) {
	
		this->BulletposX_ = posX;
		this->BulletposY_ = posY;
		this->radius_ = radius;
		this->speed_ = speed;
		this->isShot_ = isShot;
}
void Bullet::Move() {
		if (this->isShot_ == 1) {
			this->BulletposY_-= this->speed_;
		}
		if (this->BulletposY_+ this->radius_ < 0) {
			this->isShot_ = 0;
		}
}

void Bullet::Draw() {
     

if (this->isShot_ == 1) {
			Novice::DrawEllipse(this->BulletposX_, this->BulletposY_, this->radius_, this->radius_, 0.0f, BLUE, kFillModeSolid);
}
	
}
