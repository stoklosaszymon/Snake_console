#pragma once

class Map {	
public:
	static const int width = 30;
	static const int height = 20;
	int map[height][width];

	Map();
	void setMap();
	void drawMap();
	void updateMap();
	int add();
};

