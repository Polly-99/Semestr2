#include "TPair.h"
#include <iostream>
TPair::TPair()
	: first(0)
	, second(0)
{ }
TPair::~TPair()
{ }
TPair::TPair(int f, int s)
	: first(f)
	, second(s)
{ }
bool TPair::ravn()
{
	if (first == second)
	{
		return 1;
	}
	return 0;
}
int TPair::peremn()
{
	int a = first * second;
	return a;
}
TPair TPair:: operator - (TPair* A) // (a, b) - (c, d) = (a - b, c - d)
{
	TPair C;
	C.first = first - second;
	C.second = A->first - A->second;
	return C;
}
void TPair::Print()
{
	std::cout << "(" << first << ", " << second << ")" << std::endl;
}