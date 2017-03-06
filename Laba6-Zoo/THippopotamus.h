#include "TArtiodactyla.h"
class THippopotamus : public TArtiodactyla
{
public:
	THippopotamus(const std::string & name);

	virtual void Live(float time) override;

	TAnimal &Birth(TAnimal& mother, TAnimal& father);
};