#include "stdafx.h"
#include "Context.h"
#include "list"

using namespace std;


Context::Context()
{
}

Context::Context(list<Pest> pests, int baseFood, double percent, int mineFood)
{
	setPests(&pests);
	setBaseFood(&baseFood);
	setPercent(&percent);
	setMineFood(&mineFood);
}

void Context::setBaseFood(int * baseFood)
{
	this->_baseFood = *baseFood;
}

int* Context::getBaseFood()
{
	return &_baseFood;
}

void Context::setPests(list<Pest>* pests)
{
	this->_pests = *pests;
}

list<Pest>* Context::getPests()
{
	return &_pests;
}

void Context::setPercent(double * percent)
{
	this->_percent = *percent;
}

double* Context::getPercent()
{
	return &_percent;
}

void Context::setMineFood(int * mineFood)
{
	this->_mineFood = *mineFood;
}

int* Context::getMineFood()
{
	return &_mineFood;
}

void Context::PestsLifeCycle()
{
	Pest pest(10);
	_pests.push_front(pest);
	list<Pest>::iterator it4;
	for (it4 = _pests.begin(); it4 != _pests.end(); it4++)
	{
		it4->Eat(it4->getFood(), &_baseFood);
	}
}


Context::~Context()
{
}
