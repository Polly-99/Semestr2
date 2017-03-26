#include <exception>

class TCastException : public std::exception
{};

class TWrongSymbol : public TCastException
{
	const char * what() const
	{
		char * str = "Wrong Symbol";
		return str;
	}
};

class TTooLong : public TCastException
{
	const char * what() const
	{
		char * str = "Too Long";
		return str;
	}
};