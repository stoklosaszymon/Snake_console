#include "stdafx.h"
#include "Food.h"

Snake::Snake()
{
	position pos1(10, 10);
	snake.push_back(pos1);
}


Snake::~Snake()
{
}


void Snake::moveUp()
{
	snake[0].y -= 1;	
}

void Snake::moveDown()
{
	snake[0].y += 1;
}

void Snake::moveRight()
{
	snake[0].x += 1;
}

void Snake::moveLeft(){
	snake[0].x -= 1;
}




