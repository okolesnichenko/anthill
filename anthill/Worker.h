#pragma once
#include "Ant.h"
class Worker :
	public Ant
{
private:
	//кол - во добываемой пищи
	int mineFood;
public:
	Worker(int, int);
	void Action(int *, Context*);
	void IncreaseFood(int *, int *);
	void setMineFood(int *);
	int * getMineFood();
	~Worker();
};

