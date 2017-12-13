#include "stdafx.h"
#include "Control.h"



Control::Control()
{
}


Control::~Control()
{
}

void Control::updateMap(Snake snake_arg, Map& map_arg, Food food_arg) {
	for (auto part : snake_arg.snake) {
		map_arg.map[part.y][part.x] = 3;
		}

	map_arg.map[food_arg.foodPos.y][food_arg.foodPos.x] = 2;
}

void Control::eat(Food& food_arg, Snake& snake_arg) {
	if ( snake_arg.snake[0].x == food_arg.foodPos.x && snake_arg.snake[0].y == food_arg.foodPos.y){
		food_arg.foodPos.x = rand() % (Map::width - 3) + 1;
		food_arg.foodPos.y = rand() % (Map::height - 3) + 1;

		snake_arg.snake.push_back(position(NULL, NULL));
		boostSpeed(snake_arg);
	}
	
}

void Control::updateSnake(Snake& snake_arg) {

	if (snake_arg.snake.size() > 1) {
		for (int i = snake_arg.snake.size() - 1; i >= 1 ; --i)
		{
				snake_arg.snake[i].x = snake_arg.snake[i - 1].x;
				snake_arg.snake[i].y = snake_arg.snake[i - 1].y;
		}
	}
}

void Control::boostSpeed(Snake& snake_arg) {
	if (snake_arg.snake.size() % 6 == 0) {
		snake_arg.speed -= snake_arg.speed / 5;
	}
}

void Control::direction() {
	if (GetAsyncKeyState(VK_UP)) {
		if (_snakedirection != DOWN) {
			_snakedirection = UP;
		}
	}

	if (GetAsyncKeyState(VK_DOWN)){
		if (_snakedirection != UP) {
			_snakedirection = DOWN;
		}
	}

	else if (GetAsyncKeyState(VK_LEFT)) {
		if (_snakedirection != RIGHT) {
			_snakedirection = LEFT;
		}
	}

	if (GetAsyncKeyState(VK_RIGHT)) {
		if (_snakedirection != LEFT) {
			_snakedirection = RIGHT;
		}
	}
}

bool Control::colision(Snake& snake_arg) {
	if (snake_arg.snake.front().x > (Map::width - 2) || snake_arg.snake.front().y > (Map::height - 2) || snake_arg.snake.front().y < 1 || snake_arg.snake.front().x < 1) {
		return true;
	}
	else {
		return false;
	}
}

bool Control::eatItself(Snake& snake_arg) { 
		for (int i = 1; i < snake_arg.snake.size() - 1; ++i) {
			if (snake_arg.snake.front().x == snake_arg.snake[i + 1].x && snake_arg.snake.front().y == snake_arg.snake[i + 1].y) {
				return true;
			}
	}
	return false;
}

void Control::moveSnake(Snake& snake_arg) {

	switch (_snakedirection)
	{
	case UP:
		snake_arg.moveUp();
		break;
	case DOWN:
		snake_arg.moveDown();
		break;
	case LEFT:
		snake_arg.moveLeft();
		break;
	case RIGHT:
		snake_arg.moveRight();
		break;
	default:
		break;
	}
}


void Control::gameLoop() {

	Map map;
	Snake snake;
	Control control;
	Food food;


	auto x = std::async(std::launch::async, [&map, &snake, &food, &control] () {
		while (!control.colision(snake) && !control.eatItself(snake))
		{
			map.setMap();

			control.direction();


			control.moveSnake(snake);

			control.updateMap(snake, map, food);

			control.eat(food, snake);

			control.updateSnake(snake);

			map.drawMap();

			cout << "Scores: " << snake.snake.size() * 100 << " ";

			//Sleep(snake.speed);
			std::this_thread::sleep_for(chrono::milliseconds(snake.speed));
			
			system("cls");
		}
	});

}