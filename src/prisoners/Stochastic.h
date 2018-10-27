#pragma once

#include "Prisoner.h"

class Stochastic : public Prisoner {
	Action decide(const PrisonerKnowledge& p) const;
};
