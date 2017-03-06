#pragma once
#include "TAnimal.h"
#include "TLeo.h"
#include "TCarnivora.h"
#include "TTigris.h"
#include "TArtiodactyla.h"
#include "THippopotamus.h"
#include "TGiraffa.h"
#include "TProboscidea.h"
#include "TElephas.h"
#include "TLoxodonta.h"

const float STEP = 0.5;

class TZoo
{
	typedef TAnimal * TPtrAnimal;


	/// �����
	TPtrAnimal * Animals;

	/// ������������ ����������� ��������
	size_t Capacity;

	/// ���������� ������ � ��������
	size_t NumAnimals;

	/// ����� �����
	float Time;
public:
	TZoo(size_t capacity);
	bool AddNewAnimal(TAnimal ** newAnimal);
	void Work();
	void Exchange(TZoo & zoo, int i, int j);
	void Delete(int i);
	~TZoo();
};