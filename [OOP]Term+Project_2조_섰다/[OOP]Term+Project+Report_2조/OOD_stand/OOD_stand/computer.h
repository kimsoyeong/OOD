#pragma once
#include "player.h"
using namespace std;

class computer : public player
{

private:

public:
	computer();
	~computer();

	int betting_type(int pp); //player의 betting_type 함수를 override
};

