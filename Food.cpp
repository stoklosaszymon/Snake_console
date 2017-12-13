#include "stdafx.h"
#include "Food.h"


Food::Food()
{
	srand( time(NULL) );
	position rand_pos((rand() % 37 + 1), ((rand() % 17) + 2));
	foodPos = rand_pos;
}


Food::~Food()
{
}
