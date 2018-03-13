#include "stdafx.h"
#include "Ant.h"
#include "Context.h"

Ant::Ant()
{

}

Ant::Ant(int _consumeFood)
{
	setConsumeFood(&_consumeFood);
}

void Ant::Action(int * consumeFood, Context * context)
{
	Eat(consumeFood, context->getBaseFood());
}

void Ant::Eat(int * _consumeFood, int *baseFood)
{
	*baseFood -= *_consumeFood;
}

void Ant::setConsumeFood(int * _consumeFood)
{
	this->_consumeFood = *_consumeFood;
}

int* Ant::getConsumeFood()
{
	return &_consumeFood;
}

Ant::~Ant()
{
}
