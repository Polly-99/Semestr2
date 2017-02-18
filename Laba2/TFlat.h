#include <iostream>
class TFlat
{
	private:
		double Area; //общая площадь
		double Price;//стоимость за метр квадратный
	public:
		TFlat(); // Конструктор
		void set_Param(); //Ввод параметров
		double Calculate(); //Подсчет общей стоимости
		void Print();// Печать на экран
};