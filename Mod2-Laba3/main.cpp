#include "TInteger.h"

int main()
{
	TInteger A(10), C;
	int B = A;
	std::cout << B << std::endl;
	TInteger D = 5;
	A *= D;
	std::cout << A << std::endl;
	try {
		A += 2147483646;
	}
	catch (Except & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		C = 321474836469;
	}
	catch (Except & e)
	{
		std::cout << e.what() << std::endl;
	}
	TInteger F(200);
	C = F;
	if (C == F)
	{
		try
		{
			C = F * 11234234352;
		}
		catch (Except & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
	system("pause");
}