#pragma once
#include "Larva.h"

//����� "�����"
class Uterus
{
private:
	//��� - �� ������������ ����
	int consumeFood;
	//��� - �� ��������� �������
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

