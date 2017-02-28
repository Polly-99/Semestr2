#include "TPair.h"

class TRational : public TPair
{
public:
	TRational();
	TRational(int f, int s);
	TRational operator - (TRational A);
	TRational operator + (TRational A);
	TRational operator * (TRational A);
	void Print();
};