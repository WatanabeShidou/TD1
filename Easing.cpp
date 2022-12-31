#include "Easing.h"
#include <Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>

Easing::Easing()
{
	tranceform_.x = 300;
	tranceform_.y = 350;
	
	start_ = 0;
	difference_ = 0.8;
	tween_ = 8;
	for (int x = 0; x < 5; x++) {
		posX_[x] = -50;
		time_[x] = 0;
	}
	delaytime_ = 0;
	player_.inventoryflag_ = 0;
	color_ = 0x00000000;
}

void Easing::Draw(char* keys, char* preKeys)
{
	//仮メニュー
	if (keys[DIK_E] && player_.inventoryflag_ == 0) {
		player_.inventoryflag_ = 1;
	}
	if (keys[DIK_E] && player_.inventoryflag_ == 2) {
		player_.inventoryflag_ = 3;
	}
	
	if (player_.inventoryflag_ == 1) {
		if (delaytime_ <= 0.150) {
			color_ += 1;
		}
		
		if (delaytime_ <= 0.150) {
			delaytime_ += 0.001;
		}
		if (time_[0] <= 0.5) {
			time_[0] += 0.003;
		}

		if (time_[0] <= 0.5) {
			posX_[0] += easeinquad_(time_[0], start_, difference_, tween_);
		}

		if (delaytime_ >= 0.050) {
			if (time_[1] <= 0.5) {
				time_[1] += 0.003;
			}
			if (posX_[0] == posX_[1]) {

			}
			else {
				posX_[1] += easeinquad_(time_[1], start_, difference_, tween_);
			}
		}
		if (delaytime_ >= 0.100) {
			if (time_[2] <= 0.5) {
				time_[2] += 0.003;
			}
			if (posX_[0] == posX_[2]) {

			}
			else {
				posX_[2] += easeinquad_(time_[2], start_, difference_, tween_);
			}
		}
		if (delaytime_ >= 0.150) {
			if (time_[3] <= 0.5) {
				time_[3] += 0.003;
			}
			if (posX_[0] == posX_[3]) {
				player_.inventoryflag_ = 2;
				delaytime_ = 0;
			}
			else {
				posX_[3] += easeinquad_(time_[3], start_, difference_, tween_);
			}
		}
	}

	if (player_.inventoryflag_ == 3) {
		if (delaytime_ <= 0.150) {
			delaytime_ += 0.001;
			color_ -= 1;
		}
		if (time_[0] <= 1.0) {
			time_[0] += 0.003;
		}

		if (time_[0] <= 1.0) {
			posX_[0] += easeinquad_(time_[0], start_, difference_, tween_);
		}

		if (delaytime_ >= 0.050) {
			if (time_[1] <= 1.0) {
				time_[1] += 0.003;
			}
			if (posX_[0] == posX_[1]) {

			}
			else {
				posX_[1] += easeinquad_(time_[1], start_, difference_, tween_);
			}
		}
		if (delaytime_ >= 0.100) {
			if (time_[2] <= 1.0) {
				time_[2] += 0.003;
			}
			if (posX_[0] == posX_[2]) {

			}
			else {
				posX_[2] += easeinquad_(time_[2], start_, difference_, tween_);
			}
		}
		if (delaytime_ >= 0.150) {
			if (time_[3] <= 1.0) {
				time_[3] += 0.003;
			}
			if (posX_[0] == posX_[3]) {
				
				player_.inventoryflag_ = 0;
				delaytime_ = 0;
				for (int x = 0; x < 5; x++) {
					time_[x] = 0;
					posX_[x] = -50;
				}
			}
			else {
				posX_[3] += easeinquad_(time_[3], start_, difference_, tween_);
			}
		}
	}
	//背景
	if (player_.inventoryflag_ != 0) {
		Novice::DrawBox(0, 0, 1056, 576, 0.0f, color_, kFillModeSolid);
	}
	//アイコン
	Novice::DrawSprite(posX_[0], tranceform_.y, easing_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(posX_[1], tranceform_.y+50, easing_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(posX_[2], tranceform_.y+100, easing_, 1, 1, 0.0f, WHITE);
	Novice::DrawSprite(posX_[3], tranceform_.y+150, easing_, 1, 1, 0.0f, WHITE);
	Novice::ScreenPrintf(0, 80, "%d", player_.inventoryflag_);
}
