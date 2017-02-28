class TVector 
{
protected:
	double X;
	double Y;
public:
	TVector();
	virtual ~TVector();
	TVector(double x, double y);
	virtual void Print();
};


class TNew_Vector : public TVector{
protected :
	double Z;
public :
	TNew_Vector(double x, double y, double z);
	void Print();
};

