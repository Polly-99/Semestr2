#include "TElephas.h"
#include <iostream>

TElephas::TElephas(const std::string & name)
	:TProboscidea(name)
{
	SetType(4);
	SetAge_of_Birth(30);
	SetAge_of_Death(85);
}

void TElephas::Live(float time)
	{
		if (time >= 8.f && time <= 17.f)
			std::cout << GetName() << " is eating" << std::endl;
		else if (time >= 18.f && time <= 21.f)
			std::cout << GetName() << " is washing" << std::endl;
		else if (time >= 5.f && time <= 8.f)
			std::cout << GetName() << " is walking" << std::endl;
		else
			std::cout << GetName() << " is sleeping" << std::endl;
	}

TAnimal& TElephas::Birth(TAnimal& mother, TAnimal& father)
	{
		if (mother.GetAge() > mother.GetAge_of_Birth() && father.GetAge() > father.GetAge_of_Birth())
		{
			if (mother.GetChild() == 0 && father.GetChild() == 0){
				std::string name;
				std::cout << mother.GetName() << " and " << father.GetName() << " borå new elephant" << std::endl;
				std::cout << "How do you want to call it?" << std::endl;
				std::cin >> name;
				*this = *new TElephas(name);
				mother.Children();
				father.Children();
			}
		}
		return *this;
}
