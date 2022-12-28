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
};

