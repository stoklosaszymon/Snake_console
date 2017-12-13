#pragma once
#include "snake.h"

class Food : public Snake
{
public:
	position foodPos;

	Food();
	~Food();
};

