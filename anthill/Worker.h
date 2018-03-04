#pragma once
#include "Larva.h"
class Worker :
	public Larva
{
private:
	//кол - во добываемой пищи
	int mineFood;
public:
	Worker(int, int);
	void IncreaseFood(int *, int *);
	void setMineFood(int);
	int * getMineFood();
	~Worker();
};

