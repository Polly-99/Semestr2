#include "TLoxodonta.h"
#include <iostream>

TLoxodonta::TLoxodonta(const std::string & name)
:TProboscidea(name)
{
	SetType(5);
	SetAge_of_Birth(35);
	SetAge_of_Death(80);
}

void TLoxodonta::Live(float time)
{
	if (time >= 9.f && time <= 18.f)
		std::cout << GetName() << " is eating" << std::endl;
	else if (time >= 4.f && time <= 9.f)
		std::cout << GetName() << " is washing" << std::endl;
	else if (time >= 18.f && time <= 22.f)
		std::cout << GetName() << " is walking" << std::endl;
	else
		std::cout << GetName() << " is sleeping" << std::endl;
}

TAnimal& TLoxodonta::Birth(TAnimal& mother, TAnimal& father)
{
	if (mother.GetAge() > mother.GetAge_of_Birth() && father.GetAge() > father.GetAge_of_Birth())
	{
		if (mother.GetChild() == 0 && father.GetChild() == 0){
			std::string name;
			std::cout << mother.GetName() << " and " << father.GetName() << " borå new elephant" << std::endl;
			std::cout << "How do you want to call it?" << std::endl;
			std::cin >> name;
			*this = *new TLoxodonta(name);
			mother.Children();
			father.Children();
		}
	}
	return *this;
}