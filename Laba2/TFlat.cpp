#include "TFlat.h"
TFlat::TFlat()// Конструктор
{
	Area = 0;
	Price = 0;
}
void TFlat::set_Param(){
	double area = 0, price = 0;
	std::cout << "Area: ";
	std::cin >> area;
	std::cout << "Price: ";
	std::cin >> price;
	Area = area;
	Price = price;
}
double TFlat::Calculate()//Подсчет общей стоимости
{
	double Sum = Area * Price;
	return Sum;
}
void TFlat::Print()// Печать на экран
{
	std::cout << "Area = " << Area << "\nPrice = " << Price << std::endl;
}