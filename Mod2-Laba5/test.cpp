#include "RAII.h"
#include <iostream>

int main()
{
	try
	{
		TNotCopyable obj;

		RAII ptrObj (&obj);

		obj.OpenToWrite("someFile.txt");

		obj.OpenToRead("someOtherFile.txt");

		obj.Close();
	}
	catch (const std::exception & e)
	{
		std::cout << e.what();
	}
	system("pause");
}
  