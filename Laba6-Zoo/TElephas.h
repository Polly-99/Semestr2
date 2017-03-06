#include "TProboscidea.h"

class TElephas : public TProboscidea
{
public:
	TElephas(const std::string & name);

	virtual void Live(float time) override;

	TAnimal &Birth(TAnimal& mother, TAnimal& father);
};
