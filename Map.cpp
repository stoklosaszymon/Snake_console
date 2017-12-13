#include "stdafx.h"
#include "Map.h"
#include "headers.h"

using namespace std;

Map::Map()
{
	setMap();
}


void Map::setMap() {
	for (int _height = 0; _height < Map::height; _height++)
	{
		for (int _width = 0; _width < Map::width; _width++)
		{
			map[_height][_width] = 0;
			map[_height][0] = 1;
			map[Map::height - 1][_width] = 1;
			map[_height][Map::width - 1] = 1;
			map[0][_width] = 1;
		}
	}
}

void Map::drawMap() {
	for (int height = 0; height < (Map::height); height++)
	{
		for (int width = 0; width < (Map::width); width++)
		{
			map[height][width] == 0 ? cout << ' ' : cout << '#';
		}
		cout << endl;
	}
}

