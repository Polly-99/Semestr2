#include <iostream>
class TVector
{
private:
	double * Array; // ��������� �� ������
	int Size; // ����������� �������
public:
	TVector(); // ����������� �� ���������
	TVector(int n); // ����������� 
	~TVector();//����������
	double& operator[](size_t index); //��������� � �������� �� ������� 
	TVector& operator =(const TVector& rhs);

	int Razmer(); //���������� ���������� �������
};
double operator* (double * vector1, TVector vector);//��������� ������������ ��������