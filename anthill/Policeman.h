#pragma once
#include "Larva.h"
class Policeman :
	public Larva
{
private:
	//��� � ��� ������ � ���� �����������
	//�������, �� ������� ������������� ����� ����
	double percent;
public:
	Policeman(int, double);
	void IncreaseFood(int *, double *);
	void setPercent(double);
	double * getPercent();
	~Policeman();
};

