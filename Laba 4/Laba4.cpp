#include <iostream>
#include "Laba4.h"
TVector::TVector()
	:X(0)
	,Y(0)
{ }
TVector::~TVector()
{ }
TVector::TVector(double x, double y)
	:X(x)
	,Y(y)
{ }
void TVector::Print(){
	std::cout << "x = " << X << std::endl << "y = " << Y << std::endl;
}


TNew_Vector::TNew_Vector(double x, double y, double z) : TVector(x, y)
{ 
	Z = z; 
}
void TNew_Vector::Print(){
	TVector::Print();
	std::cout << "z = " << Z << std::endl;
}