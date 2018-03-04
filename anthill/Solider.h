#pragma once
#include "Larva.h"
#include "Pest.h"
#include <list>

using namespace std;

class Solider :
	public Larva
{
private:
	//��� - �� ������������ ����������
	int countPest;
public:
	Solider(int, int);
	void KillPest(list<Pest>*);
	void setCountPest(int);
	int * getCountPest();
	~Solider();
};

