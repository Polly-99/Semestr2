#include "TRational.h"
#include <iostream>
TRational::TRational() : TPair()
{}
TRational::TRational(int f, int s) : TPair(f, s)
{ }
TRational TRational::operator - (TRational A)
{
	TRational C;
	C.first = first * A.second - A.first* second;
	C.second = second * A.second;
	return C;
}
TRational TRational::operator + (TRational A)
{
	TRational C;
	C.first = first * A.second + A.first* second;
	C.second = second * A.second;
	return C;
}
TRational TRational::operator * (TRational A)
{
	TRational C;
	C.first = first * A.first;
	C.second = second * A.second;
	return C;
}
void TRational::Print()
{
	std::cout << first << "/" << second << std::endl;
}