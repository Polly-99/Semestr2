#include "TCarnivora.h"
#include <iostream>

TCarnivora::TCarnivora(const std::string & name)
:TAnimal(name)
{
	SetClass(1);
}