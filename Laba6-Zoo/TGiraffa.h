#include "TArtiodactyla.h"
class TGiraffa : public TArtiodactyla
{
public:
	TGiraffa(const std::string & name);

	virtual void Live(float time) override;

	TAnimal &Birth(TAnimal& mother, TAnimal& father);
};