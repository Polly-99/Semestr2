#include "TCarnivora.h"

class TTigris : public TCarnivora
{
public:
	TTigris(const std::string & name);

	virtual void Live(float time) override;

	TAnimal &Birth(TAnimal& mother, TAnimal& father);
};