#include <iostream>
#include "TFlat.h"
int main()
{
	int n = 0;
	double maxSumma = 0, summa = 0;
	std::cout << "Number of flats: ";
	std::cin >> n;
	std::cout << "Max. price: ";
	std::cin >> maxSumma;
	TFlat * flat = new TFlat[n];
	// Ввод параметров квартир
	for (int i = 0; i < n; i++){
		flat[i].set_Param();
	}
	std::cout << std::endl;
	// Вывод параметров 
	for (int i = 0; i < n; i++){
		std::cout << i + 1 << ". ";
		flat[i].Print();
		std::cout << std::endl;
	}
	// Вывод квартир, стоимость которых не превышает максимальную
	std::cout << "Price <= MAX: " << std::endl;
	for (int i = 0; i < n; i++){
		summa = flat[i].Calculate();
		if (summa <= maxSumma){
			std::cout << "flat #" << i + 1<< " - " << summa << std::endl;
		}
		std::cout << std::endl; 
	}
	delete[]flat;
	system("pause");
}