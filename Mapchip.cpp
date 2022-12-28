#include "Mapchip.h"
#include <Novice.h>

Mapchip::Mapchip()
{
	blocksize_ = 32;
}

void Mapchip::Update(char* keys, char* preKeys)
{
	player_.Update(keys, preKeys);
}

void Mapchip::Draw(char* keys, char* preKeys)
{
	if (player_.inventoryflag_ == 1) {
		easing_.Draw(keys, preKeys);
	}

	Novice::ScreenPrintf(0, 0, "%f", player_.playerpos_.x);
	Novice::ScreenPrintf(0, 20, "%f", player_.playerpos_.y);
	
	
	//マップ
	int map0_[46][84]
	{
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	};
	
	//判定
	lefttopX_ = (player_.playerpos_.x - 5) / blocksize_;
	leftbottomX_ = (player_.playerpos_.x - 5) / blocksize_;
	rightbottomX_ = (player_.playerpos_.x + 32 + 5) / blocksize_;

	//左
	if (map0_[leftbottomY_][leftbottomX_] == 2 || map0_[lefttopY_][lefttopX_] == 2) {
		player_.playerpos_.x = rightbottomX_ * blocksize_ - 32;
	}

	righttopX_ = (player_.playerpos_.x  + blocksize_) / blocksize_;
	rightbottomX_ = (player_.playerpos_.x  + blocksize_) / blocksize_;

	//右
	if (map0_[rightbottomY_][rightbottomX_] == 2 || map0_[righttopY_][righttopX_] == 2) {
		player_.playerpos_.x = righttopX_ * blocksize_ - 32;
	}

	leftbottomY_ = (player_.playerpos_.y  + blocksize_) / blocksize_;
	rightbottomY_ = (player_.playerpos_.y  + blocksize_) / blocksize_;

	//床
	if (map0_[rightbottomY_][rightbottomX_] == 1 || map0_[leftbottomY_][leftbottomX_] == 1) {
		player_.playerpos_.y = leftbottomY_ * blocksize_ - blocksize_;
		player_.playerpos_.vel_ = 0;
		player_.jumpflag_ = 0;
	}
	else {
		player_.playerpos_.vel_ += 0.15;//重力
	}

	righttopY_ = (player_.playerpos_.y - 5) / blocksize_;
	lefttopY_ = (player_.playerpos_.y - 5) / blocksize_;

	//天井
	if (map0_[righttopY_][righttopX_] == 1 || map0_[lefttopY_][lefttopX_] == 1) {
		player_.playerpos_.y = lefttopY_ * blocksize_ + blocksize_ + 6;
		player_.playerpos_.vel_ = 0;
	}

	player_.playerpos_.y += player_.playerpos_.vel_;//落下処理

	player_.Draw();

	//マップの描画
	for (int y = 0; y < 46; y++) {
		for (int x = 0; x < 82; x++) {
			if (map0_[y][x] == 1) {
				Novice::DrawBox(x * blocksize_, y * blocksize_, blocksize_, blocksize_, 0.0f, BLACK, kFillModeSolid);
			}
		}
	}
	for (int y = 0; y < 46; y++) {
		for (int x = 0; x < 82; x++) {
			if (map0_[y][x] == 2) {
				Novice::DrawBox(x * blocksize_, y * blocksize_, blocksize_, blocksize_, 0.0f, RED, kFillModeSolid);
			}
		}
	}
	/*for (int y = 0; y < 46; y++) {
		for (int x = 0; x < 82; x++) {
			if (map_[y][x] == 0) {
				Novice::DrawBox(x * blocksize_, y * blocksize_, blocksize_, blocksize_, 0.0f, WHITE, kFillModeSolid);
			}
		}
	}*/
}

void Mapchip::Judgement()
{
	//判定
	lefttopX_ = player_.playerpos_.x / blocksize_;
	lefttopY_ = player_.playerpos_.y / blocksize_;

	leftbottomX_ = player_.playerpos_.x / blocksize_;
	leftbottomY_ = (player_.playerpos_.y + player_.playerpos_.radius_ - 1) / blocksize_;

	righttopX_ = (player_.playerpos_.x + player_.playerpos_.radius_ - 1) / blocksize_;
	righttopY_ = player_.playerpos_.y / blocksize_;

	rightbottomX_ = (player_.playerpos_.x + player_.playerpos_.radius_ - 1) / blocksize_;
	rightbottomY_ = (player_.playerpos_.y + player_.playerpos_.radius_ - 1) / blocksize_;
}
