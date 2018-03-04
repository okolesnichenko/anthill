#include "stdafx.h"
#include "Worker.h"


Worker::Worker(int consumeFood, int mineFood)
{
	setFood(&consumeFood);
	setMineFood(mineFood);
}

void Worker::IncreaseFood(int * mineFood, int * baseFood)
{
	*baseFood += *mineFood;
}

void Worker::setMineFood(int mineFood)
{
	this->mineFood = mineFood;
}

int * Worker::getMineFood() 
{
	return &mineFood;
}

Worker::~Worker()
{
}
