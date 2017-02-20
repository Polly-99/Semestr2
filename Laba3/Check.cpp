#include <iostream>
#include "TVector.h"
int main(){
	int n = 0;
	std::cout << "Kol-vo elementov vectora:";
	std::cin >> n;
	double * vector1 = new double[n];
	std::cout << "Vector1:";
	for (int i = 0; i < n; i++){
		std::cin >> vector1[i];
	}
	std::cout << "Vector2:";
	TVector vector2(n);
	for (int i = 0; i < n; i++){
		std::cin >> vector2[i];
	}
	TVector vector3;
	vector3 = vector2;
	double proizvedenie = 0;
	proizvedenie = vector1 * vector3;
	std::cout << proizvedenie << std::endl;
	delete []vector1;
	system("pause");
}
