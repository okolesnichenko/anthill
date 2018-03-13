#include "stdafx.h"
#include "Policeman.h"


Policeman::Policeman(int consumeFood, double percent)
{
	setConsumeFood(&consumeFood);
	setPercent(&percent);
}

void Policeman::Action(int* consumeFood, Context * context)
{
	Eat(consumeFood, context->getBaseFood());
	IncreaseFood(context->getBaseFood(), context->getPercent());
}

void Policeman::IncreaseFood(int * baseFood, double * percent)
{
	*baseFood = (int)(*baseFood * *percent);
}

void Policeman::setPercent(double * percent) 
{
	this->percent = *percent;
}

double * Policeman::getPercent()
{
	return &percent;
}

Policeman::~Policeman()
{
}
