#include "Mapchip.h"
#include <Novice.h>

Mapchip::Mapchip()
{
	blocksize_ = 32;
	stagenumber_ = 0;
	color_ = 0x00000000;
	colorchangeflag_ = 0;
	player_.inventoryflag_ = 0;
}

void Mapchip::Update(char* keys, char* preKeys)
{
	if (colorchangeflag_ == 0) {
		player_.Update(keys, preKeys);
	}
}

void Mapchip::Draw(char* keys, char* preKeys)
{

	//マップ

	int map0_[18][34]
	{
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3},
		{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	};

	int map1_[18][34]
	{
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
		{2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2},
	};
	
	if (stagenumber_ == STAGE0) {
		//map0の判定
		//判定
		lefttopX_ = (player_.playerpos_.x - 3) / blocksize_;
		leftbottomX_ = (player_.playerpos_.x - 3) / blocksize_;
		rightbottomX_ = (player_.playerpos_.x + 32 + 3) / blocksize_;

		//左
		if (map0_[leftbottomY_][leftbottomX_] == 2 || map0_[lefttopY_][lefttopX_] == 2) {
			player_.playerpos_.x = rightbottomX_ * blocksize_ - 32;
		}

		righttopX_ = (player_.playerpos_.x + blocksize_) / blocksize_;
		rightbottomX_ = (player_.playerpos_.x + blocksize_) / blocksize_;

		//右
		if (map0_[rightbottomY_][rightbottomX_] == 2 || map0_[righttopY_][righttopX_] == 2) {
			player_.playerpos_.x = righttopX_ * blocksize_ - 32;
		}

		leftbottomY_ = (player_.playerpos_.y + blocksize_) / blocksize_;
		rightbottomY_ = (player_.playerpos_.y + blocksize_) / blocksize_;

		//床
		if (map0_[rightbottomY_][rightbottomX_] == 1 || map0_[leftbottomY_][leftbottomX_] == 1) {
			player_.playerpos_.y = leftbottomY_ * blocksize_ - blocksize_;
			player_.playerpos_.vel_ = 0;
			player_.jumpflag_ = 0;
		}
		else {
			player_.playerpos_.vel_ += 0.15;//重力
		}

		righttopY_ = (player_.playerpos_.y - 3) / blocksize_;
		lefttopY_ = (player_.playerpos_.y - 3) / blocksize_;

		//天井
		if (map0_[righttopY_][righttopX_] == 1 || map0_[lefttopY_][lefttopX_] == 1) {
			player_.playerpos_.y = lefttopY_ * blocksize_ + blocksize_ + 6;
			player_.playerpos_.vel_ = 0;
		}

		player_.playerpos_.y += player_.playerpos_.vel_;//落下処理

		if (map0_[rightbottomY_][rightbottomX_] == 3 || map0_[righttopY_][righttopX_] == 3) {
			colorchangeflag_ = 1;
		}
		//画面遷移
		if (colorchangeflag_ == 1) {
			color_ += 5;
			if (color_ == 255) {
			stagenumber_ = STAGE1;
			player_.playerpos_.x = 32;
		}
		}
		
		if (colorchangeflag_ == 2) {
			color_ -= 5;
			if (color_ == 0) {
			colorchangeflag_ = 0;
		}
		}
		
	}

	if (stagenumber_ == STAGE1) {
		//画面遷移
		if (colorchangeflag_ == 1) {
			color_ -= 5;
			if (color_ == 0) {
			colorchangeflag_ = 0;
			}
		}
		
		//map1の判定
		//判定
		lefttopX_ = (player_.playerpos_.x - 3) / blocksize_;
		leftbottomX_ = (player_.playerpos_.x - 3) / blocksize_;
		rightbottomX_ = (player_.playerpos_.x + 32 + 3) / blocksize_;

		//左
		if (map1_[leftbottomY_][leftbottomX_] == 2 || map1_[lefttopY_][lefttopX_] == 2) {
			player_.playerpos_.x = rightbottomX_ * blocksize_ - 32;
		}

		righttopX_ = (player_.playerpos_.x + blocksize_) / blocksize_;
		rightbottomX_ = (player_.playerpos_.x + blocksize_) / blocksize_;

		//右
		if (map1_[rightbottomY_][rightbottomX_] == 2 || map1_[righttopY_][righttopX_] == 2) {
			player_.playerpos_.x = righttopX_ * blocksize_ - 32;
		}

		leftbottomY_ = (player_.playerpos_.y + blocksize_) / blocksize_;
		rightbottomY_ = (player_.playerpos_.y + blocksize_) / blocksize_;

		//床
		if (map1_[rightbottomY_][rightbottomX_] == 1 || map1_[leftbottomY_][leftbottomX_] == 1) {
			player_.playerpos_.y = leftbottomY_ * blocksize_ - blocksize_;
			player_.playerpos_.vel_ = 0;
			player_.jumpflag_ = 0;
		}
		else {
			player_.playerpos_.vel_ += 0.15;//重力
		}

		righttopY_ = (player_.playerpos_.y - 3) / blocksize_;
		lefttopY_ = (player_.playerpos_.y - 3) / blocksize_;

		//天井
		if (map1_[righttopY_][righttopX_] == 1 || map1_[lefttopY_][lefttopX_] == 1) {
			player_.playerpos_.y = lefttopY_ * blocksize_ + blocksize_ + 6;
			player_.playerpos_.vel_ = 0;
		}

		player_.playerpos_.y += player_.playerpos_.vel_;//落下処理

		if (player_.playerpos_.x <= 0) {
			
			colorchangeflag_ = 2;
		}
		if (colorchangeflag_ == 2) {
			color_ += 5;
			if (color_ == 255) {
			stagenumber_ = STAGE0;
			player_.playerpos_.x = 1000;
		}
		}
		
	}

	player_.Draw();//プレイヤー描画

	if (stagenumber_ == STAGE0) {
		//マップの描画
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < 34; x++) {
				if (map0_[y][x] == 1) {
					Novice::DrawBox(x * blocksize_, y * blocksize_, blocksize_, blocksize_, 0.0f, BLACK, kFillModeSolid);
				}
			}
		}
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < 34; x++) {
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
	if (stagenumber_ == STAGE1) {
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < 34; x++) {
				if (map1_[y][x] == 1) {
					Novice::DrawBox(x * blocksize_, y * blocksize_, blocksize_, blocksize_, 0.0f, BLACK, kFillModeSolid);
				}
			}
		}
		for (int y = 0; y < 18; y++) {
			for (int x = 0; x < 34; x++) {
				if (map1_[y][x] == 2) {
					Novice::DrawBox(x * blocksize_, y * blocksize_, blocksize_, blocksize_, 0.0f, RED, kFillModeSolid);
				}
			}
		}
	}

	easing_.Draw(keys, preKeys);//メニュー描画
	
	//画面遷移
	Novice::DrawBox(0, 0, 1056, 576, 0.0f, color_, kFillModeSolid);

	Novice::ScreenPrintf(0, 0, "E : menu");
	Novice::ScreenPrintf(0, 40, "%d", player_.inventoryflag_);
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
