#include <Novice.h>
#include "Player.h"

Player::Player(int posX, int posY, int radius, int speed) {
	this->posX_ = posX;
	this->posY_ = posY;
	this->radius_ = radius;
	this->speed_ = speed;
	bullet_ = new Bullet(0, 0, 15, 8, 0);
}

Player::~Player() {
	delete bullet_;
}

void Player::Move(char * keys) {
	if (keys[DIK_A]) {
		this->posX_ -= this->speed_;
	}
    if (keys[DIK_D]) {
	this->posX_ += this->speed_;
    }
    
	 if (keys[DIK_W]) {
	this->posY_ -= this->speed_;
    }
	 if (keys[DIK_S]) {
	this->posY_ += this->speed_;
    }

	 if (this->posX_ + this->radius_ > 1280) {
		 this->posX_ = 1280 - this->radius_;
	 }
	 if (this->posX_ - this->radius_ < 0) {
		 this->posX_ = this->radius_;
	 }
	 if (this->posY_ + this->radius_ > 720) {
		 this->posY_ = 720 - this->radius_;
	 }
	 if (this->posY_ - this->radius_ < 0) {
		 this->posY_ = this->radius_;
	 }	 
}

void Player::Shot(char *keys, char *preKeys) {
	if (keys[DIK_SPACE] && preKeys[DIK_SPACE] == 0) {
		if (bullet_->isShot_ == 0) {
			bullet_->isShot_ = 1;
			bullet_->BulletposX_ = this->posX_;
			bullet_->BulletposY_ = this->posY_;
		}
	}
	bullet_->Move();
}


void Player::Draw() {
	Novice::DrawEllipse(this->posX_, this->posY_, this->radius_, this->radius_, 0.0f, RED, kFillModeSolid);
	bullet_->Draw();
}