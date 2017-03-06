#include "TGiraffa.h"
#include <iostream>

TGiraffa::TGiraffa(const std::string & name)
	:TArtiodactyla(name)
{
	SetType(0);
	SetAge_of_Birth(28);
	SetAge_of_Death(76);
}

void TGiraffa::Live(float time)
{
	if (time >= 9.f && time <= 14.f)
		std::cout << GetName() << " is eating" << std::endl;
	else if (time >= 19.f && time <= 23.f)
		std::cout << GetName() << " is sleeping" << std::endl;
	else if (time >= 4.f && time <= 7.f)
		std::cout << GetName() << " is having a rest" << std::endl;
	else
		std::cout << GetName() << " is walking" << std::endl;
}

TAnimal& TGiraffa::Birth(TAnimal& mother, TAnimal& father)
{
	if (mother.GetAge() > mother.GetAge_of_Birth() && father.GetAge() > father.GetAge_of_Birth())
	{
		if (mother.GetChild() == 0 && father.GetChild() == 0){
			std::string name;
			std::cout << mother.GetName() << " and " << father.GetName() << " borå new giraffe" << std::endl;
			std::cout << "How do you want to call it?" << std::endl;
			std::cin >> name;
			*this = *new TGiraffa(name);
			mother.Children();
			father.Children();
		}
	}
	return *this;
}
