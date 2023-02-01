#include <Novice.h>
#include "Enemy.h"
#include "Bullet.h"

Enemy::Enemy(int posX, int posY, int radius, int speed,int alive) {
    this->EnemyposX_ = posX;
    this->EnemyposY_ = posY;
    this->radius_ = radius;
    this->speed_ = speed;
    this->EnemyAlive = alive;
}

void Enemy::Move(char *keys, char *preKeys) {
    if (Enemy::EnemyAlive== 1) {
        this->EnemyposX_ += this->speed_;
        if (this->EnemyposX_ + this->radius_ > 1280 || this->EnemyposX_ - this->radius_ < 0) {
            this->speed_ = -this->speed_;
        }
    }
    if (keys[DIK_R] && preKeys[DIK_R] == 0) {
        Enemy::EnemyAlive = 1;
    }
}
 void Enemy::Draw() {
     if (Enemy::EnemyAlive == 1) {
         Novice::DrawEllipse(this->EnemyposX_, this->EnemyposY_, this->radius_, this->radius_, 0.0f, WHITE, kFillModeSolid);
     }
 }
 