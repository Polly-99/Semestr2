#include "TProboscidea.h"

class TLoxodonta : public TProboscidea
{
public:
	TLoxodonta(const std::string & name);

	virtual void Live(float time) override;
	
	TAnimal& Birth(TAnimal& mother, TAnimal& father);
};