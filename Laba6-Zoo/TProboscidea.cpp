#include "TProboscidea.h"
#include <iostream>

TProboscidea::TProboscidea(const std::string & name)
:TAnimal(name)
{
	SetClass(2);
}