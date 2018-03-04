#include "stdafx.h"
#include "Policeman.h"


Policeman::Policeman(int consumeFood, double percent)
{
	setFood(&consumeFood);
	setPercent(percent);
}

void Policeman::IncreaseFood(int * baseFood, double * percent)
{
	*baseFood = (int)(*baseFood * *percent);
}

void Policeman::setPercent(double percent) 
{
	this->percent = percent;
}

double * Policeman::getPercent()
{
	return &percent;
}

Policeman::~Policeman()
{
}
