#pragma once
class Pest
{
private:
	int consumeFood;
public:
	Pest(int);
	void Eat(int *, int *);
	void setFood(int);
	int* getFood();
	~Pest();
};

