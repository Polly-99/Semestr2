#include "THippopotamus.h"
#include <iostream>

THippopotamus::THippopotamus(const std::string & name)
	:TArtiodactyla(name)	
{
	SetType(1);
	SetAge_of_Birth(32);
	SetAge_of_Death(68);
}

void THippopotamus::Live(float time)
{
	if (time >= 6.f && time <= 11.f)
		std::cout << GetName() << " is eating" << std::endl;
	else if (time >= 12.f && time <= 17.f)
		std::cout << GetName() << " is swimming" << std::endl;
	else if (time >= 17.f && time <= 20.f)
		std::cout << GetName() << " is walking" << std::endl;
	else
		std::cout << GetName() << " is sleeping" << std::endl;
}

TAnimal& THippopotamus::Birth(TAnimal& mother, TAnimal& father)
{
	if (mother.GetAge() > mother.GetAge_of_Birth() && father.GetAge() > father.GetAge_of_Birth())
	{
		if (mother.GetChild() == 0 && father.GetChild() == 0){
			std::string name;
			std::cout << mother.GetName() << " and " << father.GetName() << " borå new hippopotamus" << std::endl;
			std::cout << "How do you want to call it?" << std::endl;
			std::cin >> name;
			*this = *new THippopotamus(name);
			mother.Children();
			father.Children();
		}	
	}
	return *this;
}
