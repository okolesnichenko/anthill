#pragma once
#include "Larva.h"

//класс "матки"
class Uterus
{
private:
	//кол - во потребляемой пищи
	int consumeFood;
	//кол - во рождаемых личинок
	int countLarva;
public:
	Uterus(int, int);
	void Eat(int *, int *);
	Larva CreateLarva(int);
	void setUterusFood(int *);
	void setCountLarva(int *);
	int* getUterusFood();
	int getCountLarva();
	~Uterus();
};

