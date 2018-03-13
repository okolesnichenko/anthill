#pragma once
#include <list>
#include "Pest.h"

using namespace std;

class Context
{
private:
	list<Pest> _pests;
	int _baseFood;
	double _percent;
	int _mineFood;
public:
	Context();
	Context(list<Pest>, int, double, int);
	void PestsLifeCycle();
	void setBaseFood(int *);
	int* getBaseFood();
	void setPercent(double *);
	double* getPercent();
	void setMineFood(int *);
	int* getMineFood();
	void setPests(list<Pest>*);
	list<Pest>* getPests();
	~Context();
};

