#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <Novice.h>
#include "Struct.h"
#include "Player.h"

class Easing
{
public:
	Easing();
	void Draw(char* keys, char* preKeys);
	Tranceform tranceform_;
	Player player_;
private:
	int easing_ = Novice::LoadTexture("./Easing.png");
	
	float easeinquad_(float time, float start, float difference, float tween) {
		time /= difference;
		if (time < 0.3) {
			return tween / 2.0 * time * time + start;
		}
		time = time - 1;
		return tween / 2.0 * (time * (time - 2) - 1) + start;
	}
	float time_[5];
	float start_;
	float difference_;
	float tween_;
	float posX_[5];
	float delaytime_;
};

