#include "stdafx.h"
#include <iostream>
#include "Larva.h"

using namespace std;

Larva::Larva()
{
	//..
}

Larva::Larva(int consumeFood)
{
	setFood(&consumeFood);
}

Larva::Larva(int *consumeFood)
{
	setFood(consumeFood);
}

void Larva::Eat(int * consumeFood, int * baseFood)
{
	*baseFood -= *consumeFood;
}
void Larva::setFood(int *consumeFood)
{
	this->consumeFood = *consumeFood;
}

int* Larva::getFood()
{
	return &consumeFood;
}

Larva::~Larva()
{
}
