#pragma once

#include "Prisoner.h"

class Stochastic : public Prisoner {
public:
	Stochastic(float coopProb, uint seed = 0);
	Action decide(const PrisonerKnowledge& p) const;
private:
	float _coopProb;
	uint _seed;
};
