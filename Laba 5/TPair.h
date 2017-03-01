class TPair 
{
protected:
	int first;
	int second;
public:
	TPair();
	TPair(int f, int s);
	virtual ~TPair();
	bool ravn();
	int peremn();
	virtual TPair operator - (TPair A);
	virtual void Print();
};
