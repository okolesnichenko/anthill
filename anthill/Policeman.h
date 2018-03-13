#pragma once
#include "Ant.h"
class Policeman :
	public Ant
{
private:
	double percent;
public:
	Policeman(int, double);
	void Action(int *, Context*);
	void IncreaseFood(int *, double *);
	void setPercent(double *);
	double * getPercent();
	~Policeman();
};

