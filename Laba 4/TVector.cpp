#include <iostream>
#include "TVector.h"
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