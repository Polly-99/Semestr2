#include "TArray.h"
#include <iostream>

int main()
{
	TArray <int, 5> arr1 { 1, 2, 5 };
	TArray <int, 5> arr2 {4, 7, 0, 2};
	std::cout << arr1[2] << std::endl;
	std::cout << arr2.front() << std::endl;
	std::cout << arr2.back() << std::endl;
	arr1.swap(arr2);
	for (int i = 0; i < arr1.size(); i++)
	{
		std::cout << arr1[i] << " ";
	}
	std::cout << std::endl;
	for (int i = 0; i < arr2.size(); i++)
	{
		std::cout << arr2[i] << " ";
	}
	std::cout << std::endl;
	system("pause");
}