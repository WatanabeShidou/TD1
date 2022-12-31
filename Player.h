#pragma once
#include "Struct.h"

class Player
{
public:
	Tranceform playerpos_;
	void Draw();
	void Update(char* keys, char* preKeys);
	Player();
	int jumpflag_;
	int inventoryflag_;
	void Reset();
private:
	int speed_;
	int menutimer_;
};

