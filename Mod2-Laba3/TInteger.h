#include <exception>
#include <iostream>


class Except : public std::exception
{
public:
	const char * what() const;
};


class TInteger
{
	int Value;
public:
	TInteger();
	TInteger(long long int i);
	~TInteger();
	TInteger(const TInteger &rhs);
	TInteger& operator = (const TInteger &rhs);
	TInteger& operator = (const long long int rhs);
	bool operator == (const TInteger &rhs) const;
	bool operator == (const long long int rhs) const;
	TInteger& operator += (const TInteger &rhs);
	TInteger& operator += (const long long int rhs);
	TInteger& operator -= (const TInteger &rhs);
	TInteger& operator -= (const long long int rhs);
	TInteger& operator *= (const TInteger &rhs);
	TInteger& operator *= (const long long int rhs);
	TInteger& operator /= (const TInteger &rhs);
	TInteger& operator /= (const long long int rhs);
	TInteger& operator %= (const TInteger &rhs);
	TInteger& operator %= (const long long int rhs);
	bool operator < (const TInteger& rhs) const;
	bool operator < (const long long int rhs) const;
	operator int();
	friend std::ostream & operator<<(std::ostream &, const TInteger &);
};

TInteger operator + (const TInteger &a, const TInteger &b);
TInteger operator + (const TInteger &a, const long long int b);
TInteger operator - (const TInteger &a, const TInteger &b);
TInteger operator - (const TInteger &a, const long long int b);
TInteger operator * (const TInteger &a, const TInteger &b);
TInteger operator * (const TInteger &a, const long long int b);
TInteger operator / (const TInteger &a, const TInteger &b);
TInteger operator / (const TInteger &a, const long long int b);
TInteger operator % (const TInteger &a, const TInteger &b);
TInteger operator % (const TInteger &a, const long long int b);
bool operator != (const TInteger &a, const TInteger &b);
bool operator != (const TInteger &a, const long long int rhs);
bool operator > (const TInteger &a, const TInteger &b);
bool operator > (const TInteger &a, const long long int b);
std::ostream & operator<<(std::ostream &out, const TInteger &str);
