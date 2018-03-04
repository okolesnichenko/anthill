#pragma once
class Larva
{
protected:
	//кол - во потребляемой пищи
	int consumeFood;
public:
	Larva();
	Larva(int);
	Larva(int *);
	//void Create();
	void Eat(int *, int *);
	void setFood(int *);
	int* getFood();
	~Larva();
};

