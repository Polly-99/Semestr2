#include "TTigris.h"
#include <iostream>

TTigris::TTigris(const std::string & name)
:TCarnivora(name)
{
	SetType(3);
	SetAge_of_Birth(20);
	SetAge_of_Death(60);
}

void TTigris::Live(float time)
{
	if (time >= 14 && time <= 18)
		std::cout << GetName() << " is eating" << std::endl;
	else if (time >= 6 && time <= 14)
		std::cout << GetName() << " is hunting" << std::endl;
	else if (time >= 1.f && time <= 5.f)
		std::cout << GetName() << " is running" << std::endl;
	else
		std::cout << GetName() << " is sleeping" << std::endl;
}

TAnimal& TTigris::Birth(TAnimal& mother, TAnimal& father)
{
	if (mother.GetAge() > mother.GetAge_of_Birth() && father.GetAge() > father.GetAge_of_Birth())
	{
		if (mother.GetChild() == 0 && father.GetChild() == 0){
			std::string name;
			std::cout << mother.GetName() << " and " << father.GetName() << " borå new tiger" << std::endl;
			std::cout << "How do you want to call it?" << std::endl;
			std::cin >> name;
			*this = *new TTigris(name);
			mother.Children();
			father.Children();
		}
	}
	return *this;
}