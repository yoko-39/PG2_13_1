#include <Novice.h>
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"

using namespace std;

const char kWindowTitle[] = "GC1B_23_ヨコヤマショウ_タイトル";
// Windowsアプリでのエントリーポイント(main関数)
	int Enemy::EnemyAlive;
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Enemy* enemy1 = new Enemy(100, 100, 20, 5,1);
	Enemy* enemy2 = new Enemy(600, 300, 20, 5,1);
    Player* player = new Player(645, 690, 30, 6);
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		player->Move(keys);
		enemy1->Move(keys, preKeys);
		enemy2->Move(keys, preKeys);
		player->Shot(keys, preKeys);

		float R = (player->bullet_->radius_ + enemy1->radius_) * (player->bullet_->radius_ + enemy1->radius_);
		float R1 = (player->bullet_->radius_ + enemy2->radius_)* (player->bullet_->radius_ + enemy2->radius_);
		float X = (player->bullet_->BulletposX_ - enemy1->EnemyposX_) * (player->bullet_->BulletposX_ - enemy1->EnemyposX_);
		float X1 = (player->bullet_->BulletposX_ - enemy2->EnemyposX_) * (player->bullet_->BulletposX_ - enemy2->EnemyposX_);
		float Y = (player->bullet_->BulletposY_ - enemy1->EnemyposY_) * (player->bullet_->BulletposY_ - enemy1->EnemyposY_);
		float Y1 = (player->bullet_->BulletposY_ - enemy2->EnemyposY_) * (player->bullet_->BulletposY_ - enemy2->EnemyposY_);
		if (R > X + Y || R1 > X1 + Y1&& player->bullet_->isShot_ == 1) {
			player->bullet_->BulletposY_ = -50;
			player->bullet_->isShot_ = 0;
			Enemy::EnemyAlive = 0;
		}

		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		player->Draw();
		enemy1->Draw();
		enemy2->Draw();
	
		
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
