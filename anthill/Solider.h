#pragma once
#include "Ant.h"
#include "Pest.h"
#include <list>

using namespace std;

class Solider :
	public Ant
{
private:
	int countPest;
public:
	Solider(int, int);
	void Action(int *, Context*);
	void KillPest(list<Pest>*);
	void setCountPest(int *);
	int * getCountPest();
	~Solider();
};

