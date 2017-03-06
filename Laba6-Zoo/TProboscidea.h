#pragma once
#include "TAnimal.h"
#include <string>

class TProboscidea : public TAnimal
{
public:

	TProboscidea(const std::string & name);

	virtual TAnimal& Birth(TAnimal& mother, TAnimal& father) = 0;

	virtual void Live(float time) override = 0;
};