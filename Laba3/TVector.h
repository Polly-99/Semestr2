#include <iostream>
class TVector
{
private:
	double * Array; // указатель на массив
	int Size; // размерность массива
public:
	TVector(); // конструктор по умолчанию
	TVector(int n); // конструктор 
	~TVector();//деструктор
	double& operator[](size_t index); //обращение к элементу по индексу 
	TVector& operator =(const TVector& rhs);

	int Razmer(); //вычисление рзмерности массива
};
double operator* (double * vector1, TVector vector);//скалярное произведение векторов