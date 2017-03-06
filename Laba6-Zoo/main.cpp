#include <thread>
#include <iostream>
#include "TZoo.h"

int main()
{
	TZoo FirstZoo(10), SecondZoo(10);
	TAnimal * Lev1 = new TLeo("Simba");
	TAnimal * Tigr1 = new TTigris("Pursh");
	TAnimal * Hippopotam1 = new THippopotamus("Hippo");
	TAnimal * Giraf1 = new TGiraffa("Gira");
	TAnimal * Elephant1 = new TElephas("Toppa");
	TAnimal * Slon1 = new TLoxodonta("Donna");
	TAnimal * Lev2 = new TLeo("Nala");
	TAnimal * Tigr2 = new TTigris("Tigritta");
	TAnimal * Hippopotam2 = new THippopotamus("Gloria");
	TAnimal * Giraf2 = new TGiraffa("Lola");
	TAnimal * Elephant2 = new TElephas("Nika");
	TAnimal * Slon2 = new TLoxodonta("Slonik");
	if (!FirstZoo.AddNewAnimal(&Lev1))
		delete Lev1;
	if (!FirstZoo.AddNewAnimal(&Lev2))
		delete Lev2;
	if (!FirstZoo.AddNewAnimal(&Hippopotam1))
		delete Lev1;
	if (!FirstZoo.AddNewAnimal(&Giraf2))
		delete Giraf2;
	if (!FirstZoo.AddNewAnimal(&Slon2))
		delete Slon2;
	if (!FirstZoo.AddNewAnimal(&Elephant1))
		delete Elephant1;
	if (!SecondZoo.AddNewAnimal(&Tigr1))
		delete Tigr1;
	if (!SecondZoo.AddNewAnimal(&Tigr2))
		delete Tigr2;
	if (!SecondZoo.AddNewAnimal(&Hippopotam2))
		delete Lev2;
	if (!SecondZoo.AddNewAnimal(&Giraf1))
		delete Giraf1;
	if (!SecondZoo.AddNewAnimal(&Slon1))
		delete Slon1;
	if (!SecondZoo.AddNewAnimal(&Elephant2))
		delete Elephant2;
	for (size_t i = 0; i < 100; ++i)
	{
		std::cout << "First Zoo:" << std::endl;
		FirstZoo.Work();
		std::cout << std::endl;
		std::cout << "Second Zoo:" << std::endl;
		SecondZoo.Work();
		std::cout << std::endl << std::endl;
		if (i == 17)
		{
			FirstZoo.Exchange(SecondZoo, 2, 3);
		}
		if (i == 37)
		{
			SecondZoo.Exchange(FirstZoo, 3, 4);
		}
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
	system("pause");
}