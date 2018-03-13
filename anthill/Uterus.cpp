#include "stdafx.h"
#include <iostream>
#include "Uterus.h"
#include "Larva.h"
using namespace std;


Uterus::Uterus()
{

}

Uterus::Uterus(int consumeFood, int countLarva)
{
	setUterusFood(&consumeFood);
	setCountLarva(&countLarva);
}

void Uterus::Eat(int * consumeFood, int * baseFood)
{
	*baseFood -= *consumeFood;
}

Larva Uterus::CreateLarva(int consumeFood)
{
	Larva larva(&consumeFood);
	return larva;
}

void Uterus::setUterusFood(int *consumeFood)
{
	this->consumeFood = *consumeFood;
}

void Uterus::setCountLarva(int *countLarva)
{
	this->countLarva = *countLarva;
}

int* Uterus::getUterusFood()
{
	return &consumeFood;
}

int Uterus::getCountLarva()
{
	return countLarva;
}

Uterus::~Uterus()
{
}
