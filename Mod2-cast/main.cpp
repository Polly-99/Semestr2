#include <iostream>
#include <exception>
#include "Class.h"

template <typename T>
T FromString(const std::string& str)
{
	throw TWrongSymbol();
}

template<>
int FromString <int>(const std::string& str)
{
	int i = 0, intStr = 0;
	bool minus = false;
	if (str[0] == '-')
	{
		minus = true;
		i = 1;
	}
	for (i; i < str.length(); i++)
	{
		if (str[i] < 48 || str[i] > 57)
			throw TWrongSymbol();
		intStr = intStr * 10 + (str[i] - 48);
	}
	if (str.length() == 1 + minus && str[minus] == 48)
		return 0;
	if (intStr - minus < 0 || str.length() > 10 + minus || (str.length() == 10 + minus &&  str[minus] - 48 > 2))
		throw TTooLong();
	if (minus)
		intStr = -intStr;
	return intStr;
}

template<>
bool FromString <bool>(const std::string& str)
{
	if (str.compare("1") == 0 || str.compare("true") == 0)
		return true;
	if (str.compare("0") == 0 || str.compare("false") == 0)
		return false;
	else
		throw TWrongSymbol();
}

template<>
float FromString <float>(const std::string& str)
{
	int i = 0;
	float floatStr = 0;
	bool minus = false;
	if (str[0] == '-')
	{
		minus = true;
		i = 1;
	}
	for (i; i < str.length(); i++)
	{
		if (str[i] < 45 || str[i] > 57 || str[i] == 47)
			throw TWrongSymbol();
	}
	i = minus;
	while (str[i] != '.' && str[i] != ',' && i < str.length())
	{
		floatStr = floatStr * 10 + (str[i] - 48);
		i++;
	}
	i++;
	float z = 0.1;
	for (i; i < str.length(); i++)
	{
		floatStr = floatStr + (str[i] - 48) * z;
		z = z * 0.1;
	}
	if (floatStr - minus > 2147483647.0)
		throw TTooLong();
	if (minus)
		floatStr = -floatStr;
	return floatStr;
}


int main()
{ 
	try {
		std::string str1 = "-2147483786";
		int intStr = FromString<int>(str1);
	}
	catch (const TCastException & e1)
	{
		std::cout << "str1:  " << e1.what() << std::endl;
	}

	try {
		std::string str2 = "true";
		int boolStr = FromString<bool>(str2);
	}
	catch (const TCastException & e2)
	{
		std::cout << "str2:  " << e2.what() << std::endl;
	}

	try {
		std::string str3 = "83a";
		int floatStr = FromString<float>(str3);
	}
	catch (const TCastException & e3)
	{
		std::cout << "str3:  " << e3.what() << std::endl;
	}
	system("pause");
}