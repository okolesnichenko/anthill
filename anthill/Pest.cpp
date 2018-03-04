#include "stdafx.h"
#include "Pest.h"


Pest::Pest(int consumeFood)
{
	setFood(consumeFood);
}	

void Pest::setFood(int consumeFood)
{
	this->consumeFood = consumeFood;
}

void Pest::Eat(int * consumeFood, int * baseFood)
{
	*baseFood -= *consumeFood;
}

int* Pest::getFood()
{
	return &consumeFood;
}

Pest::~Pest()
{
}