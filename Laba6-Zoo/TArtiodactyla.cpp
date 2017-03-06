#include "TArtiodactyla.h"
#include <iostream>

TArtiodactyla::TArtiodactyla(const std::string & name)
:TAnimal(name)
{
	SetClass(1);
}