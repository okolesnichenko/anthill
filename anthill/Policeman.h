#pragma once
#include "Larva.h"
class Policeman :
	public Larva
{
private:
	//еда и все методы с едой наследуются
	//процент, на который увеличивается запас пищи
	double percent;
public:
	Policeman(int, double);
	void IncreaseFood(int *, double *);
	void setPercent(double);
	double * getPercent();
	~Policeman();
};

