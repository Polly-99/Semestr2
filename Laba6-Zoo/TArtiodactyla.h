#pragma once
#include "TAnimal.h"
#include <string>
#include <iostream>

class TArtiodactyla: public TAnimal
{
public:

	TArtiodactyla(const std::string & name);

	virtual TAnimal& Birth(TAnimal& mother, TAnimal& father) = 0;

	virtual void Live(float time) override = 0;
};