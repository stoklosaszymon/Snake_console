#pragma once
#include "headers.h"

using namespace std;

class Snake {

public:

	enum direct {
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	struct position {
		int x;
		int y;
		position(int arg_x, int arg_y) {
			x = arg_x;
			y = arg_y;
		}
		position() {};
	};

	int speed = 100;
	vector <position> snake;
	Snake();
	~Snake();

	void moveUp();
	void moveDown();
	void moveRight();
	void moveLeft();

};

