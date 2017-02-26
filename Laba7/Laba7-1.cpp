#include <iostream>
#include <string>
int main()
{
	int kol_vo = 0, length = 0;
	std::string str;
	std::cout << "Kol-vo strok : ";
	std::cin >> kol_vo;
	std::cout << std::endl;
	for (int i = 0; i < kol_vo; i++){
		std::cout << "Stroka #" << i + 1 << std::endl;
		std::cin >> str;
		length = str.length();
		if (length == 1)
		{
			std::cout << "Palindrom" << std::endl;
		}
		for (int j = 0; j < length; j++)
		{
			if (str[j] != str[length - j - 1]) 
			{
				std::cout << "Ne palindrom" << std::endl;
				break;
			}
			if (j = length - 1)
			{
				std::cout << "Palindrom" << std::endl;
			}
		}
		std::cout << std::endl;
	}
	system("pause");
}
