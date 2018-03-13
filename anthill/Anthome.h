#pragma once
#include "Larva.h"
#include "Pest.h"
#include "Policeman.h"
#include "Solider.h"
#include "Uterus.h"
#include "Worker.h"

#include <list>

using namespace std;

class Anthome
{
private:
	Uterus uterus;
	Context context;
	list<Larva> larvas;
	list<Ant*> ants;
public:
	Anthome(Uterus,  Context);
	void UterusLifeCycle();
	void LarvasLifeCycle();
	void AntsLifeCycle();
	void Life();
	~Anthome();
};

