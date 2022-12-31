#pragma once
#include "Player.h"
#include "Easing.h"

class Mapchip
{
public:
	Mapchip();
	Player player_;
	Easing easing_;

	void Update(char* keys, char* preKeys);
	void Draw(char* keys, char* preKeys);
	void Judgement();
	int color_;
	int colorchangeflag_;
	int menuflag_;
private:
	int lefttopX_;
	int lefttopY_;
	int leftbottomX_;
	int leftbottomY_;
	int righttopX_;
	int righttopY_;
	int rightbottomX_;
	int rightbottomY_;
	int blocksize_;
	enum StageNumber {
		STAGE0,
		STAGE1,
		STAGE2,
		STAGE3,
		STAGE4,
	};
	int stagenumber_;
};

