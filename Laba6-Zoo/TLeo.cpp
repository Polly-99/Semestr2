#include <iostream>
#include "TLeo.h"

TLeo::TLeo(const std::string & name)
:TCarnivora(name)
{
	SetType(2);
	SetAge_of_Birth(25);
	SetAge_of_Death(65);
}

void TLeo::Live(float time)
{
	if (time >= 8.f && time <= 15.f)
		std::cout << GetName() << " is eating" << std::endl;
	else if (time >= 15.f && time <= 22.f)
		std::cout << GetName() << " is hunting" << std::endl;
	else if (time >= 5.f && time <= 8.f)
		std::cout << GetName() << " is running" << std::endl;
	else
		std::cout << GetName() << " is sleeping" << std::endl;
}

TAnimal& TLeo::Birth(TAnimal& mother, TAnimal& father)
{
	if (mother.GetAge() > mother.GetAge_of_Birth() && father.GetAge() > father.GetAge_of_Birth())
	{
		if (mother.GetChild() == 0 && father.GetChild() == 0){
			std::string name;
			std::cout << mother.GetName() << " and " << father.GetName() << " borå new lion" << std::endl;
			std::cout << "How do you want to call it?" << std::endl;
			std::cin >> name;
			*this = *new TLeo(name);
			mother.Children();
			father.Children();
		}
	}
	return *this;
}