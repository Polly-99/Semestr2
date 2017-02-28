#include "New.h"
#include <iostream>
TNew_Vector::TNew_Vector(double x, double y, double z) : TVector(x, y)
{
	Z = z;
}
void TNew_Vector::Print(){
	TVector::Print();
	std::cout << "z = " << Z << std::endl;
}