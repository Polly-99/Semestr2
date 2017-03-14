#include <iostream>
#include <exception>
#include "Class.h"

int intFromString(const char * str)
{
	int i = 0, intStr = 0;
	bool minus = false;
	if (str[0] == '-')
	{
		minus = true;
		i = 1;
	}
	for (i; i < strlen(str); i++)
	{
		if (str[i] < 48 || str[i] > 57)
			throw TWrongSymbol();
		intStr = intStr * 10 + (str[i] - 48);
	}

	if (intStr - minus < 0 || strlen(str) > 10 + minus || (strlen(str) == 10 + minus &&  str[minus]-48 > 2))
		throw TTooLong();
	if (minus)
		intStr = -intStr;
	return intStr;
}

bool boolFromString(const char * str)
{
	if (strcmp(str, "1") == 0 || strcmp(str, "true") == 0)
		return true;
	if (strcmp(str, "0") == 0 || strcmp(str, "false") == 0)
		return false;
	else
		throw TWrongSymbol();
}

float floatFromString(const char * str)
{
	int i = 0;
	float floatStr = 0;
	bool minus = false;
	if (str[0] == '-')
	{
		minus = true;
		i = 1;
	}
	for (i; i < strlen(str); i++)
	{
		if (str[i] < 45 || str[i] > 57 || str[i] == 47)
			throw TWrongSymbol();
	}
	i = minus;
	while (str[i] != '.' && str[i] != ',' && i < strlen(str))
	{
		floatStr = floatStr * 10 + (str[i] - 48);
		i++;
	}
	i++;
	float z = 0.1;
	for (i; i < strlen(str); i++)
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
		char * str1 = "-2147483786";
		int intStr = intFromString(str1);
	}
	catch (const TCastException & e1)
	{
		std::cout << "str1:  " << e1.what() << std::endl;
	}

	try {
		char * str2 = "true";
		int boolStr = boolFromString(str2);
	}
	catch (const TCastException & e2)
	{
		std::cout << "str2:  " << e2.what() << std::endl;
	}

	try {
		char * str3 = "83a";
		int floatStr = floatFromString(str3);
	}
	catch (const TCastException & e3)
	{
		std::cout << "str3:  " << e3.what() << std::endl;
	}
	system("pause");
}
