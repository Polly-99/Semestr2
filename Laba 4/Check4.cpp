#include <iostream>
#include "New.h"
int main(){
	int x = 0, y = 0, z = 0;
	std::cout << "Vector 1: " << std::endl << "koordinata X : ";
	std::cin >> x;
	std::cout << "koordinata Y : ";
	std::cin >> y;
	TVector A (x, y);
	
	std::cout << "Vector 2: " << std::endl << "koordinata X : ";
	std::cin >> x;
	std::cout << "koordinata Y : ";
	std::cin >> y;
	std::cout << "koordinata Z : ";
	std::cin >> z;
	TNew_Vector B(x, y, z);

	std::cout << "Vector 3: " << std::endl << "koordinata X : ";
	std::cin >> x;
	std::cout << "koordinata Y : ";
	std::cin >> y;
	std::cout << "koordinata Z : ";
	std::cin >> z;
	TVector * C = new TNew_Vector(x, y, z);

	std::cout << std::endl << "Vector 1: " << std::endl;
	A.Print();
	std::cout << std::endl << "Vector 2: " << std::endl;
	B.Print();
	std::cout << std::endl << "Vector 3: " << std::endl;
	C->Print(); //вызовется функция производного класса

	delete C;
	system("pause");
}