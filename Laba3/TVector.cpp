#include "TVector.h"
TVector::TVector()
{
	Array = nullptr;
	Size = 0;
}
TVector::~TVector()
{
	delete[] Array;
}
TVector::TVector(int n)
{
	Size = n;
	Array = new double[Size];
	for (int i = 0; i < Size; i++){
		Array[i] = 0;
	}
}
TVector&  TVector::operator =(const TVector& rhs)
{
	Size = rhs.Size;
	Array = new double[Size];
	for (int i = 0; i < Size; i++){
		Array[i] = rhs.Array[i];
	}
	return *this;
}
double& TVector::operator[](size_t index)
{
	return Array[index];
}
int TVector::Razmer(){
	return Size;
}

double operator* (double * vector1, TVector vector2){
	int size2 = vector2.Razmer();
	double proizv = 0;
	for (int i = 0; i < size2; i++){
		proizv = proizv + vector1[i] * vector2[i];
	}
	return proizv;
}