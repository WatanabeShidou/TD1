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
private:
	int speed_;
};

