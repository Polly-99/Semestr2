#include "TZoo.h"

TZoo::TZoo(size_t capacity)
: Capacity(capacity)
, NumAnimals(0)
, Time(0)
{
	Animals = new TPtrAnimal[Capacity];
	memset(Animals, 0, sizeof(TPtrAnimal)* Capacity);
}

bool TZoo::AddNewAnimal(TAnimal ** newAnimal)
{
	// Проверяем корректность входного параметра
	if (newAnimal == nullptr)
		return false;

	// Зоопарк полон, нельзя добавить нового зверя
	if (NumAnimals == Capacity)
		return false;

	// Добавляем зверя в массив
	Animals[NumAnimals] = *newAnimal;

	// Забираем зверя у старого владельца, чтобы не удалить зверя дважды
	*newAnimal = nullptr;

	// Увеличиваем счетчик
	++NumAnimals;
	return true;
}

void TZoo::Work()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		if (Animals[i] != nullptr){
			Animals[i]->Grow();
			//esli kto-to rodilsya
			for (int j = 0; j < NumAnimals; j++)
			{
				if (i != j){
					if (Animals[i]->GetType() == Animals[j]->GetType())
					{
						TAnimal * baby = nullptr;
						std::string net = "NET";
						switch (Animals[i]->GetType())
						{
						case 0: 
							baby = new TGiraffa(net);
							break;
						case 1: 
							baby = new THippopotamus(net);
							break;
						case 2: 
							baby = new TLeo(net);
							break;
						case 3: 
							baby = new TTigris(net);
							break;
						case 4: 
							baby = new TElephas(net);
							break;
						case 5: 
							baby = new TLoxodonta(net);
							break;
						}
						baby->Birth(*Animals[i], *Animals[j]);
						if (baby->GetName() != net)
							this->AddNewAnimal(&baby);
						else 
							delete baby;
					}
				}
			}
			//esli kto-to umiraet
			if (Animals[i]->GetAge() > Animals[i]->GetAge_of_Death())
			{
				std::cout << Animals[i]->GetName() << "  died!" << std::endl;
				this->Delete(i);
				i--;
			}
			else
				Animals[i]->Live(Time);
		}
	}

	Time += STEP;
	if (Time > 24.f)
		Time -= 24.f;
}

void TZoo::Exchange(TZoo & otherzoo, int i, int j)
{
	if (Animals[i]->GetClass() != otherzoo.Animals[j]->GetClass())
	{
		std::cout << "This exchange is impossible!" << std::endl;
		system("pause");
		return;
	}
	std::cout << "Exchange: " << Animals[i]->GetName() << " -> " << otherzoo.Animals[j]->GetName() << std::endl << std::endl;
	AddNewAnimal(&(otherzoo.Animals[j]));
	otherzoo.Delete(j);
	otherzoo.AddNewAnimal(&(Animals[i]));
	Delete(i);
}

void TZoo::Delete(int i)
{
	TAnimal * ptr = Animals[NumAnimals - 1];
	for (int j = i; j < NumAnimals - 1; ++j)
	{
		Animals[j] = Animals[j + 1];       
	}
	NumAnimals--;
 }

TZoo::~TZoo()
{
	for (size_t i = 0; i < NumAnimals; ++i)
	{
		delete Animals[i];
	}
	delete[] Animals;
}