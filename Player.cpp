#include "Player.h"
#include <Novice.h>

Player::Player()
{
	playerpos_.x = 100;
	playerpos_.y = 300;
	playerpos_.radius_ = 32;
	speed_ = 3;
	playerpos_.vel_ = 0;
	jumpflag_ = 0;
	inventoryflag_ = 0;
	menutimer_ = 0;
}

void Player::Reset()
{
	inventoryflag_ = 0;
}

void Player::Draw()
{
	Novice::DrawBox(playerpos_.x, playerpos_.y, playerpos_.radius_, playerpos_.radius_,
		0.0f, BLACK, kFillModeSolid);
	
}

void Player::Update(char* keys, char* preKeys)
{
	if (inventoryflag_ == 0) {
		//移動
		if (keys[DIK_D]) {
			playerpos_.x += speed_;
		}
		if (keys[DIK_A]) {
			playerpos_.x -= speed_;
		}

		//ジャンプ
		if (keys[DIK_SPACE] && jumpflag_ == 0) {
			playerpos_.vel_ = -7;
			playerpos_.y += playerpos_.vel_;
			jumpflag_ = 1;
		}
	}
		//メニュー
		if (keys[DIK_E] && inventoryflag_ == 0) {
			inventoryflag_ = 1;
		}
		if (inventoryflag_ == 1) {
			menutimer_ += 1;
		}
		if (menutimer_ >= 300) {
			if (keys[DIK_E] && inventoryflag_ == 1) {
				inventoryflag_ = 2;
				menutimer_ = 0;
			}
		}
		if (inventoryflag_ == 2) {
			menutimer_ += 1;
			if (menutimer_ >= 300) {
				inventoryflag_ = 0;
				menutimer_ = 0;
			}
		}
		Novice::ScreenPrintf(0, 20, "%d", menutimer_);
}
