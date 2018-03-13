#include "stdafx.h"
#include "Worker.h"


Worker::Worker(int consumeFood, int mineFood)
{
	setConsumeFood(&consumeFood);
	setMineFood(&mineFood);
}

void Worker::Action(int* consumeFood, Context * context)
{
	Eat(consumeFood, context->getBaseFood());
	IncreaseFood(context->getMineFood(), context->getBaseFood());
}

void Worker::IncreaseFood(int * mineFood, int * baseFood)
{
	*baseFood += *mineFood;
}

void Worker::setMineFood(int * mineFood)
{
	this->mineFood = *mineFood;
}

int * Worker::getMineFood() 
{
	return &mineFood;
}

Worker::~Worker()
{
}
