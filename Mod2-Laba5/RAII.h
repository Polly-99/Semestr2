#include "TNotCopyable.h"
#include <iostream>

class RAII
{
	TNotCopyable * PtrTNC;
public:
	RAII() {}

	RAII(TNotCopyable * ptr)
		:PtrTNC(ptr)
	{}

	~RAII()
	{
		PtrTNC->Close();
		std::cout << "Closed!" << std::endl;
	}
};