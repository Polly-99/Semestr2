#include "TCarnivora.h"

class TLeo : public TCarnivora
{
public:
	TLeo(const std::string & name);

	virtual void Live(float time) override;

	TAnimal &Birth(TAnimal& mother, TAnimal& father);
};