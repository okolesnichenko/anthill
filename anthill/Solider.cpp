#include "stdafx.h"
#include "Solider.h"

Solider::Solider(int consumeFood, int countPest)
{
	setConsumeFood(&consumeFood);
	setCountPest(&countPest);
}

void Solider::Action(int* consumeFood, Context * context)
{
	Eat(consumeFood, context->getBaseFood());
	KillPest(context->getPests());
}

void Solider::KillPest(list<Pest>* pests)
{
	if (!(pests->empty()) && (bool)(rand()%2))
	{
		pests->pop_front();
	}
}

void Solider::setCountPest(int * countPest) 
{
	this->countPest = *countPest;
}

int* Solider::getCountPest()
{
	return &countPest;
}

Solider::~Solider()
{
}
