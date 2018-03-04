#pragma once
class Pest
{
private:
	//ך - גמ סתוהאולמי והû
	int consumeFood;
public:
	Pest(int);
	void Eat(int *, int *);
	void setFood(int);
	int* getFood();
	~Pest();
};

