#include <iostream>
#include <thread>
#include "InfInt.h"

void factorial(int num, InfInt * res)
{
	(*res) = 1;
	for (int i = 2; i <= num; i++)
		(*res) = (*res) * i;
}

InfInt C(int k, int n)
{
	if (k < 0 || n < 0 || k > n)
		throw std::exception();
	if (k == n || k == 0)
		return 1;
	InfInt res_1 = 0, res_2 = 0, res_3 = 0;
	std::thread Thread_1(factorial, n, &res_1), Thread_2(factorial, k, &res_2), Thread_3(factorial, (n - k), &res_3);
	Thread_1.join();
	Thread_2.join();
	Thread_3.join();
	InfInt res = res_1 / (res_2 * res_3);
	return res;
}

int main()
{
	try
	{
		InfInt Count = C(8, 12);
		std::cout << Count << std::endl;
	}
	catch (...)
	{ }
	system("pause");
}