// anthill.cpp: ���������� ����� ����� ��� ����������� ����������.
//
/*7.	����������. ���� ��������: �����, �������, �����������, �������, �������, ���������. ������ ����������� �������� ��������� ����������� ������.
���������� ����� ����� ���� �������������� �������. ����� ������� �������, �� ������� ��������� �������, ����������� ��� ������� ������� � ��� ����� �����, 
������� ��������� ����� ���������� � ����� ����, ����������� �������� ��������� ����� ���������� ���� � ���� ������ ������, ������� �������� ���� � ���� ������ �����������, 
������� ������ ����. ����� ����� ��������� ���������:
�	��� - �� ������������ ����;
�	��� - �� ��������� �������.
������� ����� ��������� ���������
�	��� - �� ������������ ����;
�	��� - �� ������������ ����������.
����������� ������� ��������� ��������� :
�	��� - �� ������������ ����;
�	�������, �� ������� ������������� ����� ����.
������� ����� ��������� ��������� :
�	��� - �� ������������ ����;
�	��� - �� ���������� ����.
������� ����� ������ ���� �������� : ��� - �� ������������ ����.����� ��������� ����� ������� ������ ���������� � ����� �����.
��� ��������� ����� ������ ������ �� ���� ��������������� �����, ����� ��� ���������� ���, � ������� ����������� �������.
�������� ������ ����������� ��� ��������� �������� ����� ��������, ����������, ����.
*/

#include "stdafx.h"
#include <iostream>
#include <list>
#include <dos.h>
//������ 
#include "Larva.h"
#include "Pest.h"
#include "Policeman.h"
#include "Solider.h"
#include "Uterus.h"
#include "Worker.h"

using namespace std;

int baseFood = 1000;

void Action(Uterus *uterus, list<Larva> * larvas,  list<Solider> * soliders, list<Policeman> * policemans, list<Worker> * workers, list<Pest> * pests)
{	
	while (baseFood > 0)
	{
		// 1. ����� ���.
		uterus->Eat(uterus->getUterusFood(), &baseFood);

		// 2. ����� ������ �������. ���������� � ������.
		for (int i = 0; i < uterus->getCountLarva(); i++)
		{
			larvas->push_front(uterus->CreateLarva(20));
		}

		// 3. ��� ��������� � ����������� ������� ����.
		// 4. ��� ��������� � ������������ ������ �������������.
		list<Larva>::iterator it;
		for (it = (*larvas).begin(); it != (*larvas).end(); it++)
		{
			// ������.
			it->Eat(it->getFood(), &baseFood);
			// ������������� � 50% ������.
			if ((bool)(rand()%2))
			{
				switch ((bool)(rand()%3))
				{
				case(0):
				{
					Solider solider(20, 1);
					soliders->push_front(solider);
					break;
				}
				case(1):
				{
					Policeman poliseman(15, 1.02);
					policemans->push_front(poliseman);
					break;
				}
				case(2):
				{
					Worker worker(10, 15);
					workers->push_front(worker);
					break;
				}
				default:
					break;
				}
				// �������� �������.
				if ((it != larvas->end()) && (it != larvas->begin()))
				{
					larvas->pop_front();
				}
			}
		}
		larvas->pop_front();
		
		// 5. �������, �����������, ������� ������ � �������� ���� ������.
		// ��������.
		if (!soliders->empty())
		{
			list<Solider>::iterator it1;
			for (it1 = (*soliders).begin(); it1 != (*soliders).end(); it1++)
			{
				// ������.
				it1->Eat(it1->getFood(), &baseFood);
				// ������� ����������.
				if (pests->empty())
				{
					it1->KillPest(pests);
				}
			}
		}
		// �����������.
		if (!policemans->empty())
		{
			list<Policeman>::iterator it2;
			for (it2 = (*policemans).begin(); it2 != (*policemans).end(); it2++)
			{
				// ������.
				it2->Eat(it2->getFood(), &baseFood);

				// ���������� ���.
				it2->IncreaseFood(&baseFood, it2->getPercent());
			}
		}
		// �������.
		if (!workers->empty())
		{
			list<Worker>::iterator it3;
			for (it3 = (*workers).begin(); it3 != (*workers).end(); it3++)
			{
				// ������.
				it3->Eat(it3->getFood(), &baseFood);

				// ���������� ���.
				it3->IncreaseFood(it3->getMineFood(), &baseFood);
			}
		}
		// 6. ��������� ��������� ������ �������� � ������ ���.
		// ��������.
		Pest pest(10);
		pests->push_front(pest);

		if (!workers->empty())
		{
			list<Pest>::iterator it4;
			for (it4 = (*pests).begin(); it4 != (*pests).end(); it4++)
			{
				// ������.
				it4->Eat(it4->getFood(), &baseFood);
			}
		}

		// �����.
		// ��� ������ �� ������, �� �� ����������, ��� ������� ����.
		cout << "Utherus: " << "1" << " Larvas: " << larvas->size() << " Soliders: " << soliders->size() << " Policemans: " << policemans->size()
								 << " Workers: " << workers->size() << " Pests: "<< pests->size() << " Base Food: "<< baseFood <<'\n';
	}
}

int main()
{
	Uterus uterus(50, 2);
	list<Larva> larvas;
	list<Solider> soliders;
	list<Policeman> policemans;
	list<Worker> workers;
	list<Pest> pests;
	Action(&uterus, &larvas, &soliders, &policemans, &workers, &pests);
	 
	cout << baseFood;

    return 0;
}


