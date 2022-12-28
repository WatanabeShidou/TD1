#include "Player.h"
#include <Novice.h>

Player::Player()
{
	playerpos_.x = 100;
	playerpos_.y = 300;
	playerpos_.radius_ = 32;
	speed_ = 5;
	playerpos_.vel_ = 0;
	jumpflag_ = 0;
	inventoryflag_ = 0;
}

void Player::Draw()
{
	Novice::DrawBox(playerpos_.x, playerpos_.y, playerpos_.radius_, playerpos_.radius_,
		0.0f, BLACK, kFillModeSolid);
}

void Player::Update(char* keys, char* preKeys)
{
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

	//メニュー
	if (keys[DIK_E] && inventoryflag_ == 0) {
		inventoryflag_ = 1;
	}
	if (keys[DIK_E] && inventoryflag_ == 2) {
		inventoryflag_ = 3;
	}
}
