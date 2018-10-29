#pragma once

#include "Prisoner.h"

class TwoTitsForTat : public Prisoner {
public:
	Action decide(const PrisonerKnowledge& p) const;
};
