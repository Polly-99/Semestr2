#include "TInteger.h"

const char * Except::what() const
{
	char * str = "ERROR! OverFlow!";
	return str;
}

/////

void Check( const long long int data)
{
	if (data < -2147483647 || data > 2147483647)
		throw Except();
}

////////

TInteger::TInteger()
:Value(0)
{}

TInteger::TInteger(long long int i)
{
	Check(i);
	Value = i;
}

TInteger::~TInteger()
{}

TInteger::TInteger(const TInteger &rhs)
:Value(rhs.Value)
{}

TInteger& TInteger::operator = (const TInteger &rhs)
{
	if (Value == rhs.Value)
		return *this;
	Value = rhs.Value;
	return *this;
}

TInteger& TInteger::operator = (const long long int rhs)
{
	if (Value == rhs)
		return *this;
	Check(rhs);
	Value = rhs;
	return *this;
}

bool TInteger::operator == (const TInteger &rhs) const
{
	if (Value == rhs.Value)
		return true;
	return false;
}

bool TInteger::operator == (const long long int rhs) const
{
	if (Value == rhs)
		return true;
	return false;
}

TInteger& TInteger::operator += (const TInteger &rhs)
{
	Check((long long int) Value + rhs.Value);
	Value += rhs.Value;
	return *this;
}

TInteger& TInteger::operator += (const long long int rhs)
{
	Check((long long int) Value + rhs);
	Value += rhs;
	return *this;
}

TInteger& TInteger::operator -= (const TInteger &rhs)
{
	Check((long long int) Value - rhs.Value);
	Value -= rhs.Value;
	return *this;
}

TInteger& TInteger::operator -= (const long long int rhs)
{
	Check((long long int) Value - rhs);
	Value -= rhs;
	return *this;
}

TInteger& TInteger::operator *= (const TInteger &rhs)
{
	Check((long long int) Value * rhs.Value);
	Value *= rhs.Value;
	return *this;
}

TInteger& TInteger::operator *= (const long long int rhs)
{
	{
		Check((long long int) Value * rhs);
		Value *= rhs;
		return *this;
	}
}
TInteger& TInteger::operator /= (const TInteger &rhs)
{
	Value /= rhs.Value;
	return *this;
}
 
TInteger& TInteger::operator /= (const long long int rhs)
{
	Value /= rhs;
	return *this;
}

TInteger& TInteger::operator %= (const TInteger &rhs)
{
	Value %= rhs.Value;
	return *this;
}

TInteger& TInteger::operator %= (const long long int rhs)
{
	Value %= rhs;
	return *this;
}

bool TInteger::operator < (const TInteger& rhs) const
{
	if (Value < rhs.Value)
		return true;
	return false;
}

bool TInteger::operator < (const long long int rhs) const
{
	if (Value < rhs)
		return true;
	return false;
}

TInteger::operator int()
{
	return Value;
}

///////

TInteger operator + (const TInteger &a, const TInteger &b)
{
	TInteger summa(a);
	summa += b;
	return summa;
}


TInteger operator + (const TInteger &a, const long long int b)
{
	TInteger summa(a);
	summa += b;
	return summa;
}

TInteger operator - (const TInteger &a, const TInteger &b)
{
	TInteger razn(a);
	razn -= b;
	return razn;
}
TInteger operator - (const TInteger &a, const long long int b)
{
	TInteger razn(a);
	razn -= b;
	return razn;
}

TInteger operator * (const TInteger &a, const TInteger &b)
{
	TInteger proizv(a);
	proizv *= b;
	return proizv;
}

TInteger operator * (const TInteger &a, const long long int b)
{
	TInteger proizv(a);
	proizv *= b;
	return proizv;
}

TInteger operator / (const TInteger &a, const TInteger &b)
{
	TInteger chast(a);
	chast /= b;
	return chast;
}

TInteger operator / (const TInteger &a, const long long int b)
{
	TInteger chast(a);
	chast /= b;
	return chast;
}

TInteger operator % (const TInteger &a, const TInteger &b)
{
	TInteger ost(a);
	ost %= b;
	return ost;
}

TInteger operator % (const TInteger &a, const long long int b)
{
	TInteger ost(a);
	ost %= b;
	return ost;
}

bool operator != (const TInteger &a, const TInteger &b)
{
	if (a == b) 
		return false;
	return true;
}

bool operator != (const TInteger &a, const long long int rhs)
{
	if (a == rhs)
		return false;
	return true;
}

bool operator > (const TInteger &a, const TInteger &b)
{
	if (a < b || a == b)
		return false;
	return true;
}

bool operator >(const TInteger &a, const long long int b)
{
	if (a < b || a == b)
		return false;
	return true;
}

std::ostream & operator<<(std::ostream &out, const TInteger &tInt)
{
	out
		<< tInt.Value;
	return out;
}