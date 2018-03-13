#include "stdafx.h"
#include "Anthome.h"
#include <iostream>

using namespace std;

Anthome::Anthome(Uterus uterus, Context context)
{
	this->context = context;
	this->uterus = uterus;
}

void Anthome::UterusLifeCycle()
{
	uterus.Eat(uterus.getUterusFood(), context.getBaseFood());

	for (int i = 0; i < uterus.getCountLarva(); i++)
	{
		larvas.push_front(uterus.CreateLarva(12));
	}
}

void Anthome::LarvasLifeCycle()
{
	list<Larva>::iterator it;
	for (it = larvas.begin(); it != larvas.end(); it++)
	{
		it->Eat(it->getFood(), context.getBaseFood());

		if ((bool)(rand() % 2))
		{
			switch ((rand() % 3))
			{
			case(0):
			{
				Ant * ant = new Solider(20, 1);;
				ants.push_front(ant);
				break;
			}
			case(1):
			{
				Ant * ant = new Policeman(15, *context.getPercent());
				ants.push_front(ant);
				break;
			}
			case(2):
			{
				Ant * ant = new Worker(10, *context.getMineFood());
				ants.push_front(ant);
				break;
			}
			default:
				break;
			}
			if ((it != larvas.end()) && (it != larvas.begin()))
			{
				larvas.pop_front();
			}
		}
	}
}

void Anthome::AntsLifeCycle()
{
	list<Ant*>::iterator it;
	for (it = ants.begin(); it != ants.end(); it++)
	{
		(*it)->Action((*it)->getConsumeFood(), &context);
	}
}


void Anthome::Life()
{
	while (*context.getBaseFood()>0)
	{
		UterusLifeCycle();
		LarvasLifeCycle();
		AntsLifeCycle();
		context.PestsLifeCycle();
		cout <<" Uterus : " << "1" << " Larvas : "<< larvas.size() <<" Ants : "<< ants.size() <<" Pests : " << context.getPests()->size() << " Base Food : " << *context.getBaseFood() << "\n";
	}

}

Anthome::~Anthome()
{
	ants.clear();
}
