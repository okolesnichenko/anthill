#pragma once
#include "Context.h"

class Ant
{
protected:
	int _consumeFood;
public:
	Ant();
	Ant(int);
	void setConsumeFood(int *);
	int * getConsumeFood();
	void Action(int *, Context*);
	void Eat(int *, int *);
	~Ant();
};

