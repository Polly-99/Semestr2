#pragma once
#include <string>
class TAnimal
{
	std::string Name;
	size_t Age;
	size_t Age_of_Death;
	size_t Age_of_Birth;
	int Class;
	int Type;
	bool Child;
public:
	TAnimal();
	TAnimal(const std::string & name);
	virtual ~TAnimal() = default;
	virtual void Live(float time) = 0;
	std::string GetName() const;

	virtual TAnimal& Birth( TAnimal& mother,TAnimal& father) = 0;
	size_t GetAge() const;
	size_t GetAge_of_Death() const;
	size_t GetAge_of_Birth() const;
	int GetType();
	int GetClass();
	void SetAge_of_Birth(size_t age);
	void SetAge_of_Death(size_t age);
	void SetType(int i);
	void SetClass(int i);
	void Children();
	int GetChild();
	void Grow();
	TAnimal& operator = (TAnimal& rhs);
};