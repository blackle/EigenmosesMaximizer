#pragma once

#include "Prisoner.h"

class Yandere : public Prisoner {
public:
	Yandere(uint target);
	Action decide(const PrisonerKnowledge& p) const;
private:
	uint _target;
};
