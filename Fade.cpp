#include "Fade.h"
#include <Novice.h>

Fade::Fade()
{
	color_ = 0x00000000;
	colorchangeflag_ = 0;
}

void Fade::Draw()
{
	Novice::DrawBox(0, 0, 1056, 576, 0.0f, color_, kFillModeSolid);
}

void Fade::Update()
{
	if (colorchangeflag_ == 1) {
		color_ += 5;
	}
	if (color_ == 255) {
		colorchangeflag_ = 2;
	}
	if (colorchangeflag_ == 2) {
		color_ -= 5;
	}
	if (color_ == 0) {
		colorchangeflag_ = 0;
	}
}
