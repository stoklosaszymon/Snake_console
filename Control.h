#pragma once
#include "Map.h"
#include "Food.h" 
#include "headers.h"
#include <future>

class Control : public Map, public Snake
{
public:
	

	direct _snakedirection = UP;


	Control();
	~Control();
	void updateMap(Snake snake, Map& map, Food food);
	void gameLoop();
	void direction();
	void eat(Food& food, Snake& snake);
	void updateSnake(Snake & snake);
	void moveSnake(Snake& snake);
	void move2(Snake& snake_arg);
	bool eatItself(Snake& snake);
	bool colision(Snake& snake);
	void boostSpeed(Snake& snake);
};

