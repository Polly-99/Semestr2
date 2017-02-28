#include "TVector.h"
class TNew_Vector : public TVector{
protected:
	double Z;
public:
	TNew_Vector(double x, double y, double z);
	void Print();
};