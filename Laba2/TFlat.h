#include <iostream>
class TFlat
{
	private:
		double Area; //����� �������
		double Price;//��������� �� ���� ����������
	public:
		TFlat(); // �����������
		void set_Param(); //���� ����������
		double Calculate(); //������� ����� ���������
		void Print();// ������ �� �����
};