#include "TAnimal.h"
#include <iostream>
TAnimal::TAnimal()
: Name()
, Age(0)
, Age_of_Death(0)
, Age_of_Birth(0)
, Class(-1)
, Type(-1)
, Child(0)
{ }

TAnimal::TAnimal(const std::string & name)
: Name(name)
, Age(0)
, Age_of_Death(0)
, Age_of_Birth(0)
, Class(-1)
, Type(-1)
, Child(0)
{ }

std::string TAnimal::GetName() const
{
	return Name;
}

size_t TAnimal::GetAge() const
{
	return Age;
}

void TAnimal::Grow()
{
	Age++;
}

size_t TAnimal::GetAge_of_Death() const
{
	return Age_of_Death;
}

size_t TAnimal::GetAge_of_Birth() const
{
	return Age_of_Birth;
}

void TAnimal::SetAge_of_Birth(size_t age)
{
	Age_of_Birth = age;
}

void TAnimal::SetAge_of_Death(size_t age)
{
	Age_of_Death = age;
}

TAnimal& TAnimal::operator = (TAnimal& rhs)
{
	Name = rhs.Name;
	Age = rhs.Age;
	Age_of_Birth = rhs.Age_of_Birth;
	Age_of_Death = rhs.Age_of_Death;
	return *this;
}

void TAnimal::SetClass(int i)
{
	Class = i;
}

void TAnimal::SetType(int i)
{
	Type = i;
}

int TAnimal::GetClass()
{
	return Class;
}

int TAnimal::GetType()
{
	return Type;
}

void TAnimal::Children()
{
	Child = 1;
}

int TAnimal::GetChild()
{
	return Child;
}

