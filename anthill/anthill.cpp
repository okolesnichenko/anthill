// anthill.cpp: определяет точку входа для консольного приложения.
//
/*7.	Муравейник. Типы объектов: матка, солдаты, полицейские, рабочие, личинки, вредители. Каждый представиль является отдельным экземпляром класса.
Муравейник имеет склад пищи фиксированного размера. Матка создает личинки, из личинок выводятся солдаты, полицейские или рабочие муравьи и ест очень много, 
солдаты уменьшают число вредителей и много едят, полицейские помогают увеличить число добываемой пищи и едят меньше солдат, рабочие добывают пищу и едят меньше полицейских, 
личинки только едят. Матка имеет следующие параметры:
•	кол - во потребляемой пищи;
•	кол - во рождаемых личинок.
Солдаты имеют следующие параметры
•	кол - во потребляемой пищи;
•	кол - во уничтожаемых вредителей.
Полицейские имеются следующие параметры :
•	кол - во потребляемой пищи;
•	процент, на который увеличивается запас пищи.
Рабочие имеют следующие параметры :
•	кол - во потребляемой пищи;
•	кол - во добываемой пищи.
Личинки имеют только один параметр : кол - во потребляемой пищи.Через некоторое время личинки должны разродится в новую форму.
При изменении формы личнки должны об этом сигнализировать матку, чтобы она определила тип, в который превратится личинка.
Показать работу муравейника для различных значений числа муравьев, вредителей, пищи.
*/

#include "stdafx.h"
#include <iostream>
#include <list>
#include <dos.h>
//Классы 
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
		// 1. Матка ест.
		uterus->Eat(uterus->getUterusFood(), &baseFood);

		// 2. Матка содает личинку. Помещается в список.
		for (int i = 0; i < uterus->getCountLarva(); i++)
		{
			larvas->push_front(uterus->CreateLarva(20));
		}

		// 3. Все созданные и сущствующие личинки едят.
		// 4. Все созданные и существующие личнки преобразуются.
		list<Larva>::iterator it;
		for (it = (*larvas).begin(); it != (*larvas).end(); it++)
		{
			// Кушают.
			it->Eat(it->getFood(), &baseFood);
			// Преобразуются с 50% шансом.
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
				// Удаление личинок.
				if ((it != larvas->end()) && (it != larvas->begin()))
				{
					larvas->pop_front();
				}
			}
		}
		larvas->pop_front();
		
		// 5. Солдаты, полицейские, рабочие кушают и выолняют свою работу.
		// Соладаты.
		if (!soliders->empty())
		{
			list<Solider>::iterator it1;
			for (it1 = (*soliders).begin(); it1 != (*soliders).end(); it1++)
			{
				// Кушает.
				it1->Eat(it1->getFood(), &baseFood);
				// Убивает вредителей.
				if (pests->empty())
				{
					it1->KillPest(pests);
				}
			}
		}
		// Полицейские.
		if (!policemans->empty())
		{
			list<Policeman>::iterator it2;
			for (it2 = (*policemans).begin(); it2 != (*policemans).end(); it2++)
			{
				// Кушает.
				it2->Eat(it2->getFood(), &baseFood);

				// Увеличение еды.
				it2->IncreaseFood(&baseFood, it2->getPercent());
			}
		}
		// Рабочие.
		if (!workers->empty())
		{
			list<Worker>::iterator it3;
			for (it3 = (*workers).begin(); it3 != (*workers).end(); it3++)
			{
				// Кушает.
				it3->Eat(it3->getFood(), &baseFood);

				// Увеличение еды.
				it3->IncreaseFood(it3->getMineFood(), &baseFood);
			}
		}
		// 6. Вредители создаются каждую итерацию и кушают еду.
		// Рождение.
		Pest pest(10);
		pests->push_front(pest);

		if (!workers->empty())
		{
			list<Pest>::iterator it4;
			for (it4 = (*pests).begin(); it4 != (*pests).end(); it4++)
			{
				// Кушает.
				it4->Eat(it4->getFood(), &baseFood);
			}
		}

		// Вывод.
		// Так делать не хорошо, но мы условились, что личинка одна.
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


