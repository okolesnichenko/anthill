#pragma once
#include "Ant.h"
class Worker :
	public Ant
{
private:
	int mineFood;
public:
	Worker(int, int);
	void Action(int *, Context*);
	void IncreaseFood(int *, int *);
	void setMineFood(int *);
	int * getMineFood();
	~Worker();
};

