#include <iostream>
#include "TRational.h"
int main()
{
	int a = 0, b = 0, c = 0, d = 0;
	std::cout << "Pair A: "<< std::endl << "first number: ";
	std::cin >> a;
	std::cout << "second number: ";
	std::cin >> b;   
	TPair A(a, b);
	if (A.ravn()) 
	{
		std::cout << "first == second" << std::endl;
	}
	else
	{
		std::cout << "first != second" << std::endl;
	}
	std::cout << "first * second = " << A.peremn()<< std::endl;
	TPair B(2, 3);
	TPair H;
	H = A - &B;
	std::cout << "pair A - (2, 3) = ";
	H.Print();


	std::cout << std::endl << "Drob' C: " << std::endl;
	std::cout << "Chislitel': ";
	std::cin >> a;
	std::cout << "Znamenatel': ";
	std::cin >> b;
	TRational C(a, b);
	C.Print();
	std::cout << std::endl << "Drob' D: " << std::endl;
	std::cout << "Chislitel': ";
	std::cin >> c;
	std::cout << "Znamenatel': ";
	std::cin >> d;
	TRational D(c, d);
	D.Print();

	TRational E;
	E = C - D;
	std::cout << std::endl <<  "C - D = ";
	E.Print();
	E = C + D;
	std::cout << "C + D = ";
	E.Print();
	E = C * D;
	std::cout << "C * D = ";
	E.Print();
	system("pause");
}